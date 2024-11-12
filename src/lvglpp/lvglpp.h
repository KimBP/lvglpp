/** \file lvglpp.h
 *  \brief Base header for LVGL C++ wrapper.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once
#include "lvgl.h"

/** \namespace lvgl
 *  \brief LVGL C++ wrappers.
 */
namespace lvgl {

    /** \fn void init()
     *  \brief Initializes LVGL.
     */
    inline void init() {
        lv_init();    
    }

    /** \fn bool is_initialized()
     *  \brief Tells if LVGL is initialized.
     *  \returns true if LVGL is initialized, false otherwise.
     */
    inline bool is_initialized() {
        return lv_is_initialized();
    }

#if LV_ENABLE_GC || !LV_MEM_CUSTOM

    /** \fn void deinit()
     *  \brief De-initializes LVGL.
     */
    inline void deinit() {
        lv_deinit();
    }

#endif

}
