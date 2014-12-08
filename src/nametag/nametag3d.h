#pragma once

#include "nametag.h"

class Nametag3d : public Nametag
{
    PUBLISHED:
        Nametag3d();
        ~Nametag3d();
        
    public:
        virtual void tick();
        void set_billboard_offset(float offset);
        
    protected:
        virtual ChatBalloon* get_speech_balloon();
        virtual ChatBalloon* get_thought_balloon();
        virtual void billboard();
        
        float m_bb_offset;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            Nametag::init_type();
            register_type(_type_handle, "Nametag3d", Nametag::get_class_type());
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
