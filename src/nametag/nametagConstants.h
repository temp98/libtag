#pragma once

#include <luse.h>
#include <vector>
#include <map>

#define CLICKSTATE_NORMAL    0
#define CLICKSTATE_CLICK     1
#define CLICKSTATE_HOVER     2
#define CLICKSTATE_DISABLED  3

typedef std::vector<LVecBase4f> color_tuple_t; // (LVecBase4f, LVecBase4f)
typedef std::vector<color_tuple_t> color_tuple_tuple_t; // ((LVecBase4f, LVecBase4f), (LVecBase4f, LVecBase4f))
typedef std::map<int, color_tuple_tuple_t> state_map_t; // {state: color_tuple_tuple_t}
typedef std::map<int, color_tuple_t> state_map_simple_t; // {state: color_tuple_t}

namespace NametagConstants
{
    enum ChatFlags
    {
        CF_speech = 1,
        CF_thought = 2,
        CF_quicktalker = 4,
        CF_timeout = 8,
        CF_page_button = 16,
        CF_quit_button = 32,
        CF_reversed = 64,
        CF_no_quit_button = 128
    };

    enum ColorCode 
    {
        CC_normal,
        CC_no_chat,
        CC_non_player,
        CC_suit,
        CC_toon_building,
        CC_suit_building,
        CC_house_building,
        CC_speed_chat,
        CC_free_chat
    };
    
    enum WhisperType
    {
        WT_normal,
        WT_quick_talker,
        WT_system,
        WT_battle_SOS,
        WT_emote,
        WT_toontown_boarding_group
    };
    
    
    typedef std::map<ColorCode, state_map_t> color_map_t; // {cc: state_map_t}
    typedef std::map<WhisperType, state_map_simple_t> whisper_color_map_t; // {wt: state_map_simple_t}

    static color_map_t nametag_colors;
    static whisper_color_map_t whisper_colors;
}

BEGIN_PUBLISH
LVecBase4f get_name_fg(NametagConstants::ColorCode cc, int clickstate);
bool does_color_code_exist(NametagConstants::ColorCode cc);

color_tuple_t get_whisper_colors(NametagConstants::WhisperType wt, int clickstate);
bool does_whisper_type_exist(NametagConstants::WhisperType wt);
END_PUBLISH
