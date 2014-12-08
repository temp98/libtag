#pragma once

#include "nametag3d.h"

class NametagFloat3d : public Nametag3d
{
    PUBLISHED:
        NametagFloat3d();
        ~NametagFloat3d();
        
    public:
        virtual void tick();
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            Nametag3d::init_type();
            register_type(_type_handle, "NametagFloat3d", Nametag3d::get_class_type());
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
