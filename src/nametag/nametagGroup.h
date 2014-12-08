#pragma once

#include "nametag.h"
#include "nametag2d.h"
#include "nametag3d.h"
#include "nametagConstants.h"
#include "nametagGlobals.h"

#include <pandabase.h>
#include <genericAsyncTask.h>
#include <nodePath.h>

class MarginManager; // fwd decl

typedef std::vector<Nametag*> nametag_vec_t;
typedef std::vector<std::wstring> chat_page_vec_t;

class NametagGroup : public TypedObject
{
    PUBLISHED:
        NametagGroup();
        ~NametagGroup();
        
        void destroy();
        
        Nametag2d* get_nametag_2d();
        Nametag3d* get_nametag_3d();
        
        PT(PandaNode) get_name_icon();
        
        unsigned int get_num_chat_pages();
        void set_page_number(int page);
        
        bool get_chat_stomp();
        const std::wstring get_chat();
        const std::wstring get_stomp_text();
        float get_stomp_delay();
        
        const std::string get_unique_id();
        
        bool has_button();

        void set_active(bool active);
        bool is_active();

        void set_avatar(NodePath* avatar);
        void set_font(PT(TextFont) font);
        void set_color_code(NametagConstants::ColorCode cc);
        void set_name(const std::wstring& name);
        void set_display_name(const std::wstring& name);
        void set_qt_color(LVecBase4f color);

        void set_chat(const std::wstring& chat_string, int chat_flags);
        void set_contents(int contents);
        void clear_shadow();
        void clear_chat();
        
        void add_nametag(Nametag* nametag);
        void remove_nametag(Nametag* nametag);
        
        void manage(MarginManager* manager);
        void unmanage(MarginManager* manager);
        
        void set_name_wordwrap(float wordwrap);
        
    private:
        buttons_map_t get_buttons();
                
        void update_nametag(Nametag* nametag);
        void update_tags();
        void update_chat(const std::wstring& chat_string, int chat_flags);
        
        void start_chat_timeout();
        void stop_chat_timeout();

        AsyncTask::DoneStatus update_stomp();
        AsyncTask::DoneStatus do_chat_timeout();
        AsyncTask::DoneStatus tick();
        
        static AsyncTask::DoneStatus update_stomp_task(GenericAsyncTask* task, void* data);
        static AsyncTask::DoneStatus do_chat_timeout_task(GenericAsyncTask* task, void* data);
        static AsyncTask::DoneStatus tick_task(GenericAsyncTask* task, void* data);
        
        Nametag2d* m_nametag_2d;
        Nametag3d* m_nametag_3d;
        PT(PandaNode) m_icon;
        
        PT(AsyncTask) m_chat_timeout_task;
        PT(AsyncTask) m_tick_task;
        PT(AsyncTask) m_stomp_task;
        
        PT(TextFont) m_font;
        std::wstring m_name;
        std::wstring m_display_name;
        std::wstring m_stomp_text;
        
        LVecBase4f m_qt_color;
        
        NametagConstants::ColorCode m_color_code;
        NodePath* m_avatar;
        bool m_active;
        
        chat_page_vec_t m_chat_pages;
        int m_chat_page;
        int m_chat_flags;
        
        MarginManager* m_manager;
        nametag_vec_t m_nametags;
        bool m_visible_3d;
        int m_stomp_flags;
        
        unsigned int m_serial;
        static unsigned int NametagGroup::NametagGroup_serial;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            TypedObject::init_type();
            register_type(_type_handle, "NametagGroup", TypedObject::get_class_type());
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
