/** \file msgbox.cpp
 *  \brief Implementation file for C++ wrapper for lv_msgbox_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "msgbox.h"
#if LV_USE_MSGBOX

namespace lvgl::widgets {

    MessageBox::MessageBox(Object & parent) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(nullptr));
    }

    MessageBox::MessageBox(const std::string & title, const std::string & txt,
                           const std::vector<std::string> & btn_txts,
                           bool add_close_btn)
                           : MessageBox()
                           {
        this->initialize(title, txt, btn_txts, add_close_btn);
    }

    MessageBox::MessageBox(Object & parent, const std::string & title, const std::string & txt,
                           const std::vector<std::string> & btn_txts,
                           bool add_close_btn)
                           : MessageBox(parent)
                           {
        this->initialize(title, txt, btn_txts, add_close_btn);
    }

    void MessageBox::initialize(const std::string & title, const std::string & txt,
                                const std::vector<std::string> & btn_txts,
                                bool add_close_btn) {
        add_title(title);
        add_text(txt);

        for(auto & btn_txt : btn_txts) {
            add_footer_button(btn_txt);
        }

        if (add_close_btn) add_close_button();
    }

    Object MessageBox::add_title(const std::string & title) {
        return Object(lv_msgbox_add_title(this->raw_ptr(), title.c_str()));
    }

    Object MessageBox::add_header_button(const void* icon) {
        return Object(lv_msgbox_add_header_button(this->raw_ptr(), icon));
    }

    Object MessageBox::add_text(const std::string & text) {
        return Object(lv_msgbox_add_text(this->raw_ptr(), text.c_str()));
    }

    Object MessageBox::add_footer_button(const std::string & text) {
        return Object(lv_msgbox_add_footer_button(this->raw_ptr(), text.c_str()));
    }

    Object MessageBox::add_close_button() {
        return Object(lv_msgbox_add_close_button(this->raw_ptr()));
    }

    Object MessageBox::get_title() const {
        return Object(lv_msgbox_get_title(const_cast<lv_cls_ptr>(this->raw_ptr())));
    }

    Object MessageBox::get_content() const {
        return Object(lv_msgbox_get_content(const_cast<lv_cls_ptr>(this->raw_ptr())));
    }

    Object MessageBox::get_footer() const {
        return Object(lv_msgbox_get_footer(const_cast<lv_cls_ptr>(this->raw_ptr())));
    }

#ifdef MISSING_PORT
    uint16_t MessageBox::get_active_btn() const {
        return lv_msgbox_get_active_btn(const_cast<lv_cls_ptr>(this->raw_ptr()));
    }

    std::string MessageBox::get_active_btn_text() const {
        return std::string(lv_msgbox_get_active_btn_text(const_cast<lv_cls_ptr>(this->raw_ptr())));
    }
#endif

    void MessageBox::close() {
        lv_msgbox_close(this->raw_ptr());
    }

    void MessageBox::close_async() {
        lv_msgbox_close_async(this->raw_ptr());
    }

}
#endif // LV_USE_MSGBOX