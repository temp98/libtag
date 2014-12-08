#pragma once

#include "nametagConstants.h"
#include "nametagGlobals.h"
#include "clickablePopup.h"

class ChatBalloon; // fwd decl
class NametagGroup; // fwd decl

#include <pandabase.h>
#include <pointerTo.h>

class Nametag : public ClickablePopup
{
    friend class NametagGroup;
    
    PUBLISHED:
        Nametag(bool is_3d=false);
        ~Nametag();
        
        void set_contents(int contents);
        void set_avatar(NodePath* avatar);
        
    public:
        virtual void tick()=0;
        virtual void destroy();
        
        static const int C_name;
        static const int C_speech;
        static const int C_thought;

        static const float name_padding;
        static const float chat_alpha;
    
    protected:
        virtual void click_state_changed();
        virtual void update();
        
        NodePath get_button();
        
        virtual void show_balloon(ChatBalloon* balloon, const std::wstring& text);
        virtual void show_thought();
        virtual void show_speech();
        virtual void show_name();
        
        virtual ChatBalloon* get_speech_balloon()=0;
        virtual ChatBalloon* get_thought_balloon()=0;
        
        int m_contents;
        NodePath m_inner_np;
        
        float m_wordwrap;
        float m_chat_wordwrap;

        PT(TextFont) m_font;
        std::wstring m_name;
        std::wstring m_display_name;
        
        LVecBase4f m_qt_color;
        NametagConstants::ColorCode m_color_code;

        NodePath* m_avatar;
        NodePath m_icon;
        
        buttons_map_t m_buttons;
        
        LVecBase4f m_name_fg;
        LVecBase4f m_name_bg;
        LVecBase4f m_chat_fg;
        LVecBase4f m_chat_bg;
        
        std::wstring m_chat_string;
        int m_chat_flags;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            ClickablePopup::init_type();
            register_type(_type_handle, "Nametag", ClickablePopup::get_class_type());
        }
        
        virtual TypeHandle get_type() const
        {
            return get_class_type();
        }
        
        virtual TypeHandle force_init_type()
        {
            init_type();
            return get_class_type();
        }

    private:
        static TypeHandle _type_handle;
};
