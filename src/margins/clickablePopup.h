#pragma once

#include <pandabase.h>
#include <pandaNode.h>
#include <nodePath.h>
#include <mouseWatcher.h>
#include <mouseWatcherRegion.h>
#include <eventReceiver.h>

typedef void(*callback_t)(const Event* ev);
typedef std::map<std::string, callback_t> event_table_t;

class ClickablePopup : public EventReceiver, public PandaNode
{
    PUBLISHED:
        ClickablePopup(NodePath* camera=NULL);
        ~ClickablePopup();
        
    public:
        virtual void destroy();
        virtual void set_click_region_event(const std::string& event);
        
        int get_click_state();
        virtual void click_state_changed()=0;
        
        static void handle_event(const Event* ev, void* data);
        
    protected:
        const std::string get_event(const std::string& pattern);
        void update_click_state();
        void update_click_region(float left, float right, float bottom, float top);
        
        PT(MouseWatcher) m_mouse_watcher;
        NodePath* m_cam;
        
        bool m_disabled;
        bool m_clicked;
        bool m_hovered;
        
        int m_click_state;
        std::string m_click_event;
        std::string m_name;
        PT(MouseWatcherRegion) m_region;

    private:
        void mouse_enter(const Event* ev);
        void mouse_leave(const Event* ev);
        void button_down(const Event* ev);
        void button_up(const Event* ev);
        
        void accept(const std::string& ev);
        void ignore_all();
        
        static unsigned int ClickablePopup_serial;
        
    // Type handle
    public:
        static TypeHandle get_class_type()
        {
            return _type_handle;
        }
        
        static void init_type()
        {
            PandaNode::init_type();
            register_type(_type_handle, "ClickablePopup", PandaNode::get_class_type());
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
