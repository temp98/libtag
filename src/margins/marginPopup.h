#pragma once

#include "marginManager.h"

#include <pandabase.h>
#include <typedObject.h>

class MarginCell; // fwd decl

class MarginPopup : public TypedObject
{
    PUBLISHED:
        MarginPopup();
        ~MarginPopup();

        void set_visible(bool flag);
        bool get_visible();
        
        void set_priority(int priority);
        int get_priority();
        
        virtual bool is_displayed();
        
        virtual void margin_visibility_changed()=0;
        
        virtual void manage(MarginManager* manager);
        virtual void unmanage(MarginManager* manager);
        
    public:
        void set_last_cell(MarginCell* cell);
        MarginCell* get_last_cell();
        
        void set_assigned_cell(MarginCell* cell);
        MarginCell* get_assigned_cell();

    protected:
        MarginManager* m_manager;
        int m_priority;
        bool m_visible;
        MarginCell* m_last_cell;
        MarginCell* m_assigned_cell;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            TypedObject::init_type();
            register_type(_type_handle, "MarginPopup", TypedObject::get_class_type());
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
