#pragma once

#include "nametag.h"
#include "marginPopup.h"

class Nametag2d : public Nametag, public MarginPopup
{
    PUBLISHED:
        Nametag2d();
        ~Nametag2d();
        
    public:
        virtual void tick();
        virtual void margin_visibility_changed();
        virtual bool is_displayed();
        
        static const float scale_2d;
        static const float chat_alpha;
        static const float arrow_offset;
        static const float arrow_scale;
        
    protected:
        virtual void update();
        
        void consider_update_click_region();
        
        virtual void show_balloon(ChatBalloon* balloon, const std::wstring& text);
        virtual void show_name();
        
        virtual ChatBalloon* get_speech_balloon();
        virtual ChatBalloon* get_thought_balloon();
        
        NodePath* m_arrow;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            MarginPopup::init_type();
            Nametag::init_type();
            register_type(_type_handle, "Nametag2d", MarginPopup::get_class_type(),
                          Nametag::get_class_type());
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
