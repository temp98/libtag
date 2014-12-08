import subprocess
import argparse
import sys
import os

if not os.path.isdir("built\\obj"):
    os.makedirs("built\\obj")

parser = argparse.ArgumentParser()
parser.add_argument('--panda3d-dir', '-p',
                    help='Panda3D directory.')
parser.add_argument('--no-link', '-l', action='store_true',
                    help='Do not link the dynamic library. Use this if \
                    you intend to build a static library.')
parser.add_argument('--no-etc', '-e', action='store_true',
                    help='Do not compile etc tree.')
parser.add_argument('--no-nametag', '-n', action='store_true',
                    help='Do not compile nametag tree.')
parser.add_argument('--no-margins', '-m', action='store_true',
                    help='Do not compile margins tree.')
args = parser.parse_args()

if not args.panda3d_dir:
    print "No Panda3D directory specified, using C:\\Panda3D-1.8.1"
    panda3d_dir = "C:\\Panda3D-1.8.1"
    
else:
    panda3d_dir = args.panda3d_dir

def run_command(cmd):
    p = subprocess.Popen(cmd, stdout=sys.stdout, stderr=sys.stderr)
    ret = p.wait()
    
    if ret != 0:
        print
        print "The following command return a non-zero value (%d): %s" % (ret, cmd)
        sys.exit(ret)
        
def compile(filename):
    output = os.path.join("built", "obj", os.path.basename(filename))
    output = output.rsplit('.', 1)[0] + '.obj'
    
    cmd = "cl /nologo /c /EHsc"
    cmd += " /I" + os.path.join(panda3d_dir, "include")
    cmd += " /I" + os.path.join(panda3d_dir, "python", "include")
    cmd += " /Isrc/nametag"
    cmd += " /Isrc/margins"
    cmd += " /Isrc/etc"
    cmd += " /Fo%s %s" % (output, filename)
    
    run_command(cmd)
    
if not args.no_etc:
    compile('src/etc/config_tag.cxx')
    
if not args.no_nametag:
    compile('src/nametag/nametag.cxx')
    compile('src/nametag/nametag2d.cxx')
    compile('src/nametag/nametag3d.cxx')
    compile('src/nametag/nametagFloat3d.cxx')
    compile('src/nametag/nametagFloat2d.cxx')
    compile('src/nametag/nametagConstants.cxx')
    compile('src/nametag/nametagGlobals.cxx')
    compile('src/nametag/chatBalloon.cxx')
    compile('src/nametag/nametagGroup.cxx')

if not args.no_margins:
    compile('src/margins/marginCell.cxx')
    compile('src/margins/marginPopup.cxx')
    compile('src/margins/marginManager.cxx')
    compile('src/margins/whisperPopup.cxx')
    compile('src/margins/clickablePopup.cxx')

if not args.no_link:
    print 'Linking...'
    
    cmd = "link /DLL /nologo /ignore:4217 /ignore:4049 /out:libtag.pyd"
    cmd += " /LIBPATH:" + os.path.join(panda3d_dir, "lib")
    cmd += " /LIBPATH:" + os.path.join(panda3d_dir, "python", "libs")
    
    objects = ("nametag.obj", "nametag2d.obj", "nametag3d.obj", "nametagFloat2d.obj", "nametagFloat3d.obj",
               "nametagConstants.obj", "nametagGlobals.obj", "chatBalloon.obj", "nametagGroup.obj", "marginCell.obj",
               "marginPopup.obj", "marginManager.obj", "whisperPopup.obj", "clickablePopup.obj", "config_tag.obj")
               
    for obj in objects:
        cmd += " built/obj/" + obj
        
    libs = ("libp3framework", "libpanda", "libpandafx", "libpandaexpress", "libp3dtool", "libp3dtoolconfig", "libp3direct", "python27",
            "ws2_32", "shell32", "advapi32", "gdi32", "user32", "oleaut32", "ole32", "shell32", "wsock32", "imm32")
    for lib in libs:
        cmd += " %s.lib" % lib
        
    run_command(cmd)
    