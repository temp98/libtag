#include "nametagConstants.h"

// BEGIN AUTO GENERATED CODE

void _add_color(NametagConstants::ColorCode cc, LVecBase4f normal_name_fg, LVecBase4f normal_name_bg, LVecBase4f normal_chat_fg, LVecBase4f normal_chat_bg, LVecBase4f click_name_fg, LVecBase4f click_name_bg, LVecBase4f click_chat_fg, LVecBase4f click_chat_bg, LVecBase4f hover_name_fg, LVecBase4f hover_name_bg, LVecBase4f hover_chat_fg, LVecBase4f hover_chat_bg, LVecBase4f disabled_name_fg, LVecBase4f disabled_name_bg, LVecBase4f disabled_chat_fg, LVecBase4f disabled_chat_bg)
{
    color_tuple_t normal_name(2);
    normal_name[0] = normal_name_fg;
    normal_name[1] = normal_name_bg;
    
    color_tuple_t normal_chat(2);
    normal_chat[0] = normal_chat_fg;
    normal_chat[1] = normal_chat_bg;
    
    color_tuple_tuple_t normal(2);
    normal[0] = normal_name;
    normal[1] = normal_chat;
    
    color_tuple_t click_name(2);
    click_name[0] = click_name_fg;
    click_name[1] = click_name_bg;
    
    color_tuple_t click_chat(2);
    click_chat[0] = click_chat_fg;
    click_chat[1] = click_chat_bg;
    
    color_tuple_tuple_t click(2);
    click[0] = click_name;
    click[1] = click_chat;
    
    color_tuple_t hover_name(2);
    hover_name[0] = hover_name_fg;
    hover_name[1] = hover_name_bg;
    
    color_tuple_t hover_chat(2);
    hover_chat[0] = hover_chat_fg;
    hover_chat[1] = hover_chat_bg;
    
    color_tuple_tuple_t hover(2);
    hover[0] = hover_name;
    hover[1] = hover_chat;
    
    color_tuple_t disabled_name(2);
    disabled_name[0] = disabled_name_fg;
    disabled_name[1] = disabled_name_bg;
    
    color_tuple_t disabled_chat(2);
    disabled_chat[0] = disabled_chat_fg;
    disabled_chat[1] = disabled_chat_bg;
    
    color_tuple_tuple_t disabled(2);
    disabled[0] = disabled_name;
    disabled[1] = disabled_chat;
    
    state_map_t def;
    def[CLICKSTATE_NORMAL] = normal;
    def[CLICKSTATE_CLICK] = click;
    def[CLICKSTATE_HOVER] = hover;
    def[CLICKSTATE_DISABLED] = disabled;
    
    NametagConstants::nametag_colors[cc] = def;
}

void _add_whisper_color(NametagConstants::WhisperType wt, LVecBase4f normal_fg, LVecBase4f normal_bg, LVecBase4f click_fg, LVecBase4f click_bg, LVecBase4f hover_fg, LVecBase4f hover_bg, LVecBase4f disabled_fg, LVecBase4f disabled_bg)
{
    color_tuple_t normal(2);
    normal[0] = normal_fg;
    normal[1] = normal_bg;
    
    color_tuple_t click(2);
    click[0] = click_fg;
    click[1] = click_bg;
    
    color_tuple_t hover(2);
    hover[0] = hover_fg;
    hover[1] = hover_bg;
    
    color_tuple_t disabled(2);
    disabled[0] = disabled_fg;
    disabled[1] = disabled_bg;
    
    state_map_simple_t def;
    def[CLICKSTATE_NORMAL] = normal;
    def[CLICKSTATE_CLICK] = click;
    def[CLICKSTATE_HOVER] = hover;
    def[CLICKSTATE_DISABLED] = disabled;
    
    NametagConstants::whisper_colors[wt] = def;
}

void* __initialize_constants()
{
_add_color(NametagConstants::CC_normal,
           (0.3, 0.3, 0.7, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.3, 0.3, 0.7, 1.0), (0.2, 0.2, 0.2, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 1.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.3, 0.3, 0.7, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_no_chat,
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (1.0, 0.5, 0.5, 1.0), (0.2, 0.2, 0.2, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (1.0, 0.5, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_non_player,
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.8, 0.4, 0.0, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_suit,
           (0.2, 0.2, 0.2, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.2, 0.2, 1.0), (0.2, 0.2, 0.2, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.4, 0.4, 0.4, 1.0), (1.0, 1.0, 1.0, 0.7),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.2, 0.2, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_suit_building,
           (0.5, 0.5, 0.5, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 0.5, 1.0), (0.8, 0.8, 0.8, 0.5),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 0.5, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 0.5, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_toon_building,
           (0.2, 0.6, 0.9, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.6, 0.9, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.6, 0.9, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.6, 0.9, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_house_building,
           (0.2, 0.6, 0.9, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.2, 0.5, 1.0), (0.2, 0.2, 0.2, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 1.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.2, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_speed_chat,
           (0.0, 0.6, 0.2, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.5, 0.0, 1.0), (0.5, 0.5, 0.5, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.7, 0.2, 1.0), (1.0, 1.0, 1.0, 0.7),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.2, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_color(NametagConstants::CC_free_chat,
           (0.3, 0.3, 0.7, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.2, 0.2, 0.5, 1.0), (0.2, 0.2, 0.2, 0.6),
           (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.5, 0.5, 1.0, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.0, 0.6, 0.6, 1.0), (1.0, 1.0, 1.0, 1.0),
           (0.3, 0.3, 0.7, 1.0), (0.8, 0.8, 0.8, 0.5),
           (0.0, 0.0, 0.0, 1.0), (1.0, 1.0, 1.0, 1.0)
);

_add_whisper_color(NametagConstants::WT_normal,
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.6, 0.8, 0.6),
                   (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.7, 0.9, 0.6),
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.7, 0.8, 0.6)
);

_add_whisper_color(NametagConstants::WT_quick_talker,
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.6, 0.8, 0.6),
                   (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.7, 0.9, 0.6),
                   (0.0, 0.0, 0.0, 1.0), (0.2, 0.7, 0.8, 0.6)
);

_add_whisper_color(NametagConstants::WT_system,
                   (0.0, 0.0, 0.0, 1.0), (0.8, 0.3, 0.6, 0.6),
                   (1.0, 0.5, 0.5, 1.0), (1.0, 1.0, 1.0, 1.0),
                   (0.0, 0.0, 0.0, 1.0), (0.8, 0.4, 1.0, 1.0),
                   (0.0, 0.0, 0.0, 1.0), (0.8, 0.3, 0.6, 0.6)
);

// XXX TODO: WT_battle_SOS, WT_emote, WT_toontown_boarding_group
return NULL;
}

void* _ = __initialize_constants();

// END AUTO GENERATED CODE

LVecBase4f get_name_fg(NametagConstants::ColorCode cc, int clickstate)
{
    if (clickstate < CLICKSTATE_NORMAL || clickstate > CLICKSTATE_DISABLED)
    {
        return LVecBase4f(1);
    }
    
    if (!does_color_code_exist(cc))
    {
        return LVecBase4f(1);
    }
    
    return NametagConstants::nametag_colors[cc][clickstate][0][0];
}

bool does_color_code_exist(NametagConstants::ColorCode cc)
{
    return NametagConstants::nametag_colors.count(cc) == 1;
}

color_tuple_t get_whisper_colors(NametagConstants::WhisperType wt, int clickstate)
{
    if (clickstate < CLICKSTATE_NORMAL || clickstate > CLICKSTATE_DISABLED)
    {
        color_tuple_t ret(2);
        ret[0] = LVecBase4f(1);
        ret[1]= LVecBase4f(1);
        return ret;
    }
    
    if (!does_whisper_type_exist(wt))
    {
        color_tuple_t ret(2);
        ret[0] = LVecBase4f(1);
        ret[1]= LVecBase4f(1);
        return ret;
    }
    
    return NametagConstants::whisper_colors[wt][clickstate];
}

bool does_whisper_type_exist(NametagConstants::WhisperType wt)
{
    return NametagConstants::whisper_colors.count(wt) == 1;
}
