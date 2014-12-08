#pragma once

#include "marginCell.h"
#include "marginPopup.h"

#include <pandabase.h>
#include <typedObject.h>

typedef std::vector<MarginCell*> cell_vec_t;
typedef std::vector<MarginPopup*> popup_vec_t;

class MarginManager : public TypedObject
{
    PUBLISHED:
        MarginManager();
        ~MarginManager();
        
        MarginCell* add_grid_cell(float x, float y, float left, float right,
                                  float bottom, float top, const NodePath& parent,
                                  float aspect_ratio);
                           
        void set_cell_available(MarginCell* cell, bool available);
        void add_visible_popup(MarginPopup* popup);
        void remove_visible_popup(MarginPopup* popup);
        
    public:
        void reorganize();
        
    private: 
        cell_vec_t m_cells;
        popup_vec_t m_popups;
    
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            TypedObject::init_type();
            register_type(_type_handle, "MarginManager", TypedObject::get_class_type());
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
