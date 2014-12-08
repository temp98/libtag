#pragma once

#include "chatBalloon.h"

#include <pandabase.h>
#include <nodePath.h>
#include <audioSound.h>
#include <mouseWatcher.h>
#include <luse.h>

typedef std::map<int, NodePath> buttons_map_t;

class NametagGlobals
{
    public:
        static NodePath &camera, &arrow_model, &nametag_card_model, &toon;
        static ChatBalloon *speech_balloon_2d, *speech_balloon_3d, *thought_balloon_2d, *thought_balloon_3d;
             
        static bool master_arrows_on, master_mametags_active, onscreen_chat_forced;
        static float min_2d_alpha, max_2d_alpha;
        static buttons_map_t page_buttons, quit_buttons;
        static PT(AudioSound) click_sound, rollover_sound;
        static PT(MouseWatcher) mouse_watcher;
    
    PUBLISHED:
        void set_camera(NodePath& cam);
        void set_arrow_model(NodePath& model);
        void set_mouse_watcher(NodePath& np);
        void set_nametag_card(NodePath& model, LVecBase3f);
        void set_speech_balloon_3d(ChatBalloon* sb3d);
        void set_thought_balloon_3d(ChatBalloon* tb3d);
        void set_speech_balloon_2d(ChatBalloon* sb2d);
        void set_thought_balloon_2d(ChatBalloon* tb2d);
        void set_toon(NodePath& t);
        void set_master_arrows_on(bool flag);
        void set_master_nametags_active(bool flag);
    
        void set_min_2d_alpha(float a);
        float get_min_2d_alpha();
        void set_max_2d_alpha(float a);
        float get_max_2d_alpha();
    
        void set_onscreen_chat_forced(bool flag);
        void set_global_nametag_scale(float);
    
        void set_page_button(int state, NodePath& model);
        void set_quit_button(int state, NodePath& model);
    
        void set_rollover_sound(PT(AudioSound) s);
        void set_click_sound(PT(AudioSound) s);
};
