#pragma once

#include "nametagConstants.h"
#include "clickablePopup.h"
#include "marginPopup.h"

#include <pandabase.h>
#include <pointerTo.h>
#include <textFont.h>
#include <genericAsyncTask.h>

class MarginManager; // fwd decl

class WhisperPopup : public ClickablePopup, public MarginPopup
{
    PUBLISHED:
        WhisperPopup(const std::wstring& text, PT(TextFont) font, const NametagConstants::WhisperType whisper_type, const float timeout=10);
        ~WhisperPopup();
        
        void update_contents();
        void set_clickable(const std::wstring& sender_name, unsigned int from_id, bool);
        void manage(MarginManager* manager);
        
    private:
        static AsyncTask::DoneStatus timeout_task(GenericAsyncTask* task, void* data);
        const std::wstring& m_text;
        PT(TextFont) m_font;
        const NametagConstants::WhisperType m_whisper_type;
        const float m_timeout;
        NodePath m_inner_np;
    
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            MarginPopup::init_type();
            ClickablePopup::init_type();
            register_type(_type_handle, "WhisperPopup", MarginPopup::get_class_type(),
                          ClickablePopup::get_class_type());
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
