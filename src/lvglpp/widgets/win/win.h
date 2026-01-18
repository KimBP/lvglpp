/** \file win.h
 *  \brief Header file for C++ wrapper for lv_win_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"

#if LV_USE_WIN

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class Window
     *  \brief Wraps a lv_win_t object.
     */
    class Window : public Object {
    protected:
        /** \fn void initialize()
         *  \brief Initialize object.
         */
        void initialize();
        /** \fn void initialize(Object & parent)
         *  \brief Initialize object and assign parent object.
         *  \param parent: parent LVGL object.
         */
        void initialize(Object & parent);
    
    public:
        /** \fn Window()
         *  \brief Constructor with parameters.
         */
        Window();

        /** \fn Window(Object & parent)
         *  \brief Constructor with parameters and parent object.
         *  \param parent: parent LVGL object.
         */
        Window(Object & parent);

        /** \fn Object add_title(const std::string & txt)
         *  \brief Adds window title.
         *  \param txt: window title.
         *  \returns object for window title.
         */
        Object add_title(const std::string & txt);

        /** \fn Object add_btn(const ImageDescriptor & icon, lv_coord_t btn_w)
         *  \brief Adds window button.
         *  \param icon: image buffer for icon.
         *  \param btn_w: button width.
         *  \returns object for new button.
         */
        Object add_btn(const ImageDescriptor & icon, lv_coord_t btn_w);

        /** \fn Object add_btn(const std::string & icon, lv_coord_t btn_w)
         *  \brief Adds window button.
         *  \param icon: symbol or image path for icon.
         *  \param btn_w: button width.
         *  \returns object for new button.
         */
        Object add_btn(const std::string & icon, lv_coord_t btn_w);

        /** \fn Object get_header() const
         *  \brief Gets window header.
         *  \returns window header object.
         */
        Object get_header() const;

        /** \fn Object get_content() const
         *  \brief Gets window content. You can fill content with
         *  other objects.
         *  \returns window content object.
         */
        Object get_content() const;
    };

}
#endif // LV_USE_WIN