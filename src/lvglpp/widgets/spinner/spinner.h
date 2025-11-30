/** \file spinner.h
 *  \brief Header file for C++ wrapper for lv_spinner_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"

#if LV_USE_SPINNER

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class Spinner
     *  \brief Wraps a lv_spinner_t object.
     */
    class Spinner : public Object {
    public:
        using Object::Object;
        
        /** \fn Spinner()
         *  \brief Default constructor
         */
        Spinner();

        /** \fn Spinner(Object & parent)
         *  \brief Constructor with parent object.
         *  \param parent: parent LVGL object.
         */
        Spinner(Object & parent);

        /** \fn Spinner(uint32_t time, uint32_t arc_length)
         *  \brief Constructor with parameters.
         *  \param time: duration of spinner animation, in ms.
         *  \param arc_length: length of spinner arc, in degrees.
         */
        Spinner(uint32_t time, uint32_t arc_length);
        /** \fn Spinner(Object & parent, uint32_t time, uint32_t arc_length)
         *  \brief Constructor with parameters and parent object.
         *  \param parent: parent LVGL object.
         *  \param time: duration of spinner animation, in ms.
         *  \param arc_length: length of spinner arc, in degrees.
         */
        Spinner(Object & parent, uint32_t time, uint32_t arc_length);

        /** \fn void set_anim_params(uint32_t time, uint32_t arc_length)
         *  \brief Configure animation parametes
         *  \param time: duration of spinner animation, in ms.
         *  \param arc_length: length of spinner arc, in degrees.
         */
        void set_anim_params(uint32_t time, uint32_t arc_length);
    };

}
#endif // LV_USE_SPINNER