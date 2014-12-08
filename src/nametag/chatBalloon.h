#pragma once

#include <pandabase.h>
#include <nodePath.h>
#include <textNode.h>
#include <luse.h>
#include <typedObject.h>

class ChatBalloon : public TypedObject
{
    PUBLISHED:
        ChatBalloon(NodePath& model);
        ~ChatBalloon();
        
        NodePath generate(const std::wstring& text, PT(TextFont) font, LVecBase4* text_color=NULL,
                           LVecBase4* balloon_color=NULL, float wordwrap=10.0, NodePath* button=NULL);
        
    private:
        NodePath& m_model;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            TypedObject::init_type();
            register_type(_type_handle, "ChatBalloon", TypedObject::get_class_type());
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
