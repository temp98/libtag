#pragma once

#include <pandabase.h>
#include <nodePath.h>
#include <typedObject.h>

class MarginManager; // fwd decl
class MarginPopup; // fwd decl

class MarginCell : public NodePath, public TypedObject
{
    PUBLISHED:
        MarginCell(MarginManager* manager);
        ~MarginCell();
        
    public:
        void set_available(bool available);
        bool get_available();
        
        void set_content(MarginPopup* content);
        bool has_content();
        MarginPopup* get_content();
        
        bool is_available();
        bool is_free();
        
    private:
        bool m_available;
        MarginPopup* m_content;
        MarginManager* m_manager;
        NodePath m_content_np;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            TypedObject::init_type();
            register_type(_type_handle, "MarginCell", TypedObject::get_class_type());
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
