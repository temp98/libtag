#pragma once

#include "nametagFloat3d.h"

class NametagFloat2d : public NametagFloat3d
{
    PUBLISHED:
        NametagFloat2d();
        ~NametagFloat2d();
        
    protected:
        virtual void billboard();
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            NametagFloat3d::init_type();
            register_type(_type_handle, "NametagFloat2d", NametagFloat3d::get_class_type());
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
