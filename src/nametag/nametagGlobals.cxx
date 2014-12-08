#include "nametagGlobals.h"

#define EMPTY =NodePath()

NodePath& NametagGlobals::camera EMPTY;
NodePath& NametagGlobals::arrow_model EMPTY;
NodePath& NametagGlobals::nametag_card_model EMPTY;
NodePath& NametagGlobals::toon EMPTY;

ChatBalloon* NametagGlobals::speech_balloon_2d = NULL;
ChatBalloon* NametagGlobals::speech_balloon_3d = NULL;
ChatBalloon* NametagGlobals::thought_balloon_2d = NULL;
ChatBalloon* NametagGlobals::thought_balloon_3d = NULL;
         
bool NametagGlobals::master_arrows_on = false;
bool NametagGlobals::master_mametags_active = false;
bool NametagGlobals::onscreen_chat_forced = false;

float NametagGlobals::min_2d_alpha = 0;
float NametagGlobals::max_2d_alpha = 0;

PT(MouseWatcher) NametagGlobals::mouse_watcher = NULL;

PT(AudioSound) NametagGlobals::rollover_sound = NULL;
PT(AudioSound) NametagGlobals::click_sound = NULL;

buttons_map_t NametagGlobals::page_buttons;
buttons_map_t NametagGlobals::quit_buttons;

void NametagGlobals::set_camera(NodePath& cam)
{
    NametagGlobals::camera = cam;
}

void NametagGlobals::set_arrow_model(NodePath& model)
{
    NametagGlobals::arrow_model = model;
}

void NametagGlobals::set_mouse_watcher(NodePath& np) 
{
    NametagGlobals::mouse_watcher = DCAST(MouseWatcher, np.node());
}

void NametagGlobals::set_nametag_card(NodePath& model, LVecBase3f)
{
    NametagGlobals::nametag_card_model = model;
}

void NametagGlobals::set_speech_balloon_3d(ChatBalloon* sb3d)
{
    NametagGlobals::speech_balloon_3d = sb3d;
}

void NametagGlobals::set_thought_balloon_3d(ChatBalloon* tb3d)
{
    NametagGlobals::thought_balloon_3d = tb3d;
}

void NametagGlobals::set_speech_balloon_2d(ChatBalloon* sb2d)
{
    NametagGlobals::speech_balloon_2d = sb2d;
}

void NametagGlobals::set_thought_balloon_2d(ChatBalloon* tb2d)
{
    NametagGlobals::thought_balloon_2d = tb2d;
}

void NametagGlobals::set_toon(NodePath& t)
{
    NametagGlobals::toon = t;
}

void NametagGlobals::set_master_arrows_on(bool flag)
{
    NametagGlobals::master_arrows_on = flag;
}

void NametagGlobals::set_master_nametags_active(bool flag)
{
    NametagGlobals::master_mametags_active = flag;
}

void NametagGlobals::set_min_2d_alpha(float a)
{
    NametagGlobals::min_2d_alpha = a;
}

float NametagGlobals::get_min_2d_alpha()
{
    return NametagGlobals::min_2d_alpha;
}

void NametagGlobals::set_max_2d_alpha(float a)
{
    NametagGlobals::max_2d_alpha = a;
}

float NametagGlobals::get_max_2d_alpha()
{
    return NametagGlobals::max_2d_alpha;
}

void NametagGlobals::set_onscreen_chat_forced(bool flag)
{
    NametagGlobals::onscreen_chat_forced = flag;
}

void NametagGlobals::set_global_nametag_scale(float)
{
}

void NametagGlobals::set_page_button(int state, NodePath& model)
{
    NametagGlobals::page_buttons[state] = model;
}

void NametagGlobals::set_quit_button(int state, NodePath& model)
{
    NametagGlobals::quit_buttons[state] = model;
}

void NametagGlobals::set_rollover_sound(PT(AudioSound) s)
{
    NametagGlobals::rollover_sound = s;
}

void NametagGlobals::set_click_sound(PT(AudioSound) s)
{
    NametagGlobals::click_sound = s;
}
