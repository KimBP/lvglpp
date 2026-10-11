/** \file msgbox.cpp
 *  \brief Implementation file for C++ wrapper for lv_msgbox_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "msgbox.h"
#if LV_USE_MSGBOX

namespace lvgl::widgets {

    MessageBox::MessageBox() {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(nullptr));
    }

    MessageBox::MessageBox(Object & parent) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(parent.raw_ptr()));
    }

    MessageBox::MessageBox(const std::string & title, const std::string & txt,
                           const std::vector<std::string> & btn_txts,
                           bool add_close_btn)
                           {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(nullptr));
        this->initialize(title, txt, btn_txts, add_close_btn);
    }

    MessageBox::MessageBox(Object & parent, const std::string & title, const std::string & txt,
                           const std::vector<std::string> & btn_txts,
                           bool add_close_btn)
                           {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(parent.raw_ptr()));
        this->initialize(title, txt, btn_txts, add_close_btn);
    }

    MessageBox::MessageBox(const std::string & title, const std::string & txt) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_msgbox_create(nullptr));

        add_title(title);
        add_text(txt);
    }

    void MessageBox::initialize(const std::string & title, const std::string & txt,
                                const std::vector<std::string> & btn_txts,
                                bool add_close_btn) {
        if(!title.empty()) {
            add_title(title);
        }

        if(add_close_btn) {
            add_close_button();
        }

        if(!txt.empty()) {
            add_text(txt);
        }

        for(const auto & btn_txt : btn_txts) {
            add_footer_button(btn_txt);
        }
    }

    Object MessageBox::add_title(const std::string & title) {
        return Object(lv_msgbox_add_title(this->raw_ptr(), title.c_str()), false);
    }

    Object MessageBox::add_header_button(const void* icon) {
        return Object(lv_msgbox_add_header_button(this->raw_ptr(), icon), false);
    }

    Object MessageBox::add_text(const std::string & text) {
        return Object(lv_msgbox_add_text(this->raw_ptr(), text.c_str()), false);
    }

    Object MessageBox::add_footer_button(const std::string & text) {
        return Object(lv_msgbox_add_footer_button(this->raw_ptr(), text.c_str()), false);
    }

    Object MessageBox::add_close_button() {
        return Object(lv_msgbox_add_close_button(this->raw_ptr()), false);
    }

    Object MessageBox::get_title() const {
        return Object(lv_msgbox_get_title(const_cast<lv_cls_ptr>(this->raw_ptr())), false);
    }

    Object MessageBox::get_content() const {
        return Object(lv_msgbox_get_content(const_cast<lv_cls_ptr>(this->raw_ptr())), false);
    }

    Object MessageBox::get_footer() const {
        return Object(lv_msgbox_get_footer(const_cast<lv_cls_ptr>(this->raw_ptr())), false);
    }

    void MessageBox::close() {
        lv_msgbox_close(this->raw_ptr());
    }

    void MessageBox::close_async() {
        lv_msgbox_close_async(this->raw_ptr());
    }

}
#endif // LV_USE_MSGBOX