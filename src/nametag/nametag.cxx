#include "nametag.h"

const int Nametag::C_name = 1;
const int Nametag::C_speech = 2;
const int Nametag::C_thought = 4;
const float Nametag::name_padding = .2;
const float Nametag::chat_alpha = 1;

TypeHandle Nametag::_type_handle;

Nametag::Nametag(bool is_3d) : ClickablePopup(is_3d ? &NametagGlobals::camera : NULL), m_contents(0),
                               m_inner_np(NodePath::any_path(this).attach_new_node("nametag_contents")),
                               m_wordwrap(7.5), m_chat_wordwrap(10), m_font(NULL), m_qt_color(LVecBase4f(1)),
                               m_color_code(NametagConstants::CC_normal), m_avatar(NULL), m_icon(NodePath("icon")),
                               m_name_fg(LVecBase4f(0, 0, 0, 1)), m_name_bg(LVecBase4f(1)),
                               m_chat_fg(LVecBase4f(0, 0, 0, 1)), m_chat_bg(LVecBase4f(1)), m_chat_flags(0)
{
}

Nametag::~Nametag()
{
}
        
void Nametag::set_contents(int contents)
{
    m_contents = contents;
    update();
}

void Nametag::set_avatar(NodePath* avatar)
{
    m_avatar = avatar;
}

void Nametag::destroy()
{
    ClickablePopup::destroy();
}

void Nametag::click_state_changed()
{
    update();
}
       
NodePath Nametag::get_button()
{
    int cs = get_click_state();
    
    if (m_buttons.size() == 0)
        return NodePath::not_found();
        
    else if (cs < m_buttons.size())
        return m_buttons[cs];
    
    return m_buttons.at(0);
}
         
void Nametag::update()
{
    NametagConstants::ColorCode code = does_color_code_exist(m_color_code) ? m_color_code : NametagConstants::CC_normal;
    m_inner_np.node()->remove_all_children();

    color_tuple_tuple_t colors = NametagConstants::nametag_colors[code][get_click_state()];
    
    color_tuple_t name_colors = colors[0];
    color_tuple_t chat_colors = colors[1];
    
    m_name_fg = name_colors[0];
    m_name_bg = name_colors[1];
    
    m_chat_fg = chat_colors[0];
    m_chat_bg = chat_colors[1];

    if (m_contents & Nametag::C_thought && m_chat_flags & NametagConstants::CF_thought)
        show_thought();
        
    else if (m_contents & Nametag::C_speech && m_chat_flags & NametagConstants::CF_speech)
        show_speech();
    
    else if (m_contents & Nametag::C_name && m_display_name.size())
        show_name();
}

void Nametag::show_balloon(ChatBalloon* balloon, const std::wstring& text)
{
    LVecBase4f color = m_chat_flags & NametagConstants::CF_quicktalker ? m_qt_color : m_chat_bg;
    
    if (color.get_w() > chat_alpha)
        color.set_w(chat_alpha);
        
    m_inner_np.attach_new_node(balloon->generate(text, m_font, &m_chat_fg, &color,
                                                 m_chat_wordwrap, &get_button()).node());
}

void Nametag::show_thought()
{
    show_balloon(get_thought_balloon(), m_chat_string);
}

void Nametag::show_speech()
{
    show_balloon(get_speech_balloon(), m_chat_string);
}

void Nametag::show_name()
{
    if (m_font == NULL)
        return;
        
    m_inner_np.attach_new_node(m_icon.node());
    
    PT(TextNode) tn = new TextNode("name");
    tn->set_font(m_font);
    tn->set_align(TextNode::A_center);
    tn->set_wordwrap(m_wordwrap);
    tn->set_wtext(m_display_name);
        
    double width = tn->get_width();
    double height = tn->get_height();
        
    NodePath t = m_inner_np.attach_new_node(tn, 1);
    t.set_color(m_name_fg);
    t.set_transparency(m_name_fg.get_w() < 1 ? TransparencyAttrib::M_alpha : TransparencyAttrib::M_none);
    t.set_y(-0.25);

    NodePath panel = NametagGlobals::nametag_card_model.copy_to(m_inner_np);
    panel.set_x((tn->get_left() + tn->get_right()) / 2.);
    panel.set_z((tn->get_top() + tn->get_bottom()) / 2.);
    panel.set_scale(width + name_padding, 1, height + name_padding);
    panel.set_color(m_name_bg);
    panel.set_transparency(m_name_bg.get_w() < 1 ? TransparencyAttrib::M_alpha : TransparencyAttrib::M_none);
}
