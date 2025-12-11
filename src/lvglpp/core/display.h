/** \file display.h
 *  \brief Header file for C++ wrapper for LVGL display driver.
 *  This is a base class made to connect a screen driver with LVGL.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once
#include "../lv_wrapper.h"
#include "object.h"
#include <vector>

// we need user_data to store pointer to C++ object, otherwise we cannot
// access callbacks defined as class members.

namespace lvgl::draw { class ImageDescriptor; }

/** \namespace lvgl::core
 *  \brief LVGL core components.
 */
namespace lvgl::core {

    class Object;
    class Theme;

    /** \class Display
     *  \brief Wraps a lv_disp_t object. This is a base class to connect
     *  a screen driver with LVGL.
     */
    class Display : public PointerWrapper<lv_display_t, lv_display_delete> {
    protected:

        /** \property lv_coord_t hor_res
         *  \brief Horizontal resolution.
         */
        lv_coord_t hor_res;

        /** \property lv_coord_t ver_res
         *  \brief Vertical resolution.
         */
        lv_coord_t ver_res;

        /** \property lv_disp_draw_buf_t lv_disp_buf
         *  \brief Display buffer descriptor.
         */
        lv_draw_buf_t lv_disp_buf;

        /** \property std::vector<lv_color_t> lv_buf_1
         *  \brief Display buffer.
         */
        std::vector<uint8_t> raw_buf;

        /** \property uint32_t fb_size
         *  \brief Framebuffer size.
         */
        uint32_t fb_size;


        lv_color_format_t cf;

        /** \fn virtual void flush(const lv_area_t * area,  lv_color_t * color_map)
         *  \brief Callback to draw data on display.
         *  \param area: target draw area.
         *  \param color_map: data to draw.
         */
        virtual void flush(const lv_area_t * area,  lv_color_t * color_map) {}

        /** \fn void flush_ready()
         *  \brief Tells LVGL that flush operation is over. This must be called
         *  at the end of the flush method.
         */
        void flush_ready();
    
    public:

        /** \fn Display(lv_coord_t hor_res, lv_coord_t ver_res)
         *  \brief Constructor.
         *  \param hor_res: horizontal resolution.
         *  \param ver_res: vertical resolution.
         */
        Display(lv_coord_t hor_res, lv_coord_t ver_res);

        /** \fn void set_default()
         *  \brief Sets display as default.
         */
        void set_default();

        /** \fn bool is_default() const
         *  \brief Tells if display is set as default.
         *  \returns true if display is default display, false otherwise.
         */
        bool is_default() const;

        /** \fn lv_coord_t get_hor_res() const
         *  \brief Gets horizontal display resolution.
         *  \returns horizontal resolution.
         */
        lv_coord_t get_hor_res() const;

        /** \fn lv_coord_t get_ver_res() const
         *  \brief Gets vertical display resolution.
         *  \returns vertical resolution.
         */
        lv_coord_t get_ver_res() const;

        /** \fn lv_coord_t get_physical_hor_res() const
         *  \brief Gets physical horizontal display resolution.
         *  \returns physical horizontal resolution.
         */
        lv_coord_t get_physical_hor_res() const;

        /** \fn lv_coord_t get_physical_ver_res() const
         *  \brief Gets physical vertical display resolution.
         *  \returns physical vertical resolution.
         */
        lv_coord_t get_physical_ver_res() const;

        /** \fn lv_coord_t get_offset_x() const
         *  \brief Gets horizontal offset.
         *  \returns horizontal offset.
         */
        lv_coord_t get_offset_x() const;

        /** \fn lv_coord_t get_offset_y() const
         *  \brief Gets vertical offset.
         *  \returns vertical offset.
         */
        lv_coord_t get_offset_y() const;

        /** \fn bool get_antialiasing() const
         *  \brief Tells if antialiasing is enabled.
         *  \returns true if antialiasing is enabled, false otherwise.
         */
        bool get_antialiasing() const;

        /** \fn lv_coord_t get_dpi() const
         *  \brief Gets display DPI.
         *  \returns display DPI value.
         */
        lv_coord_t get_dpi() const;

        /** \fn void set_rotation(lv_disp_rot_t rotation)
         *  \brief Sets display rotation.
         *  \param rotation: display rotation code.
         */
        void set_rotation(lv_display_rotation_t rotation);

        /** \fn lv_disp_rot_t get_rotation() const
         *  \brief Gets display rotation.
         *  \returns display rotation code.
         */
        lv_display_rotation_t get_rotation() const;

        /** \fn Object get_scr_act() const
         *  \brief Gets active screen on this display.
         *  \returns object representing active screen.
         */
        Object get_scr_act() const;

        /** \fn Object get_scr_prev() const
         *  \brief Gets the screen before the active screen on this display.
         *  \returns object representing previous screen.
         */
        Object get_scr_prev() const;

        /** \fn Object get_layer_top() const
         *  \brief Gets access to the top layer.
         *  \returns object representing the top layer.
         */
        Object get_layer_top() const;

        /** \fn Object get_layer_sys() const
         *  \brief Gets access to the sys layer.
         *  \returns object representing the sys layer.
         */
        Object get_layer_sys() const;

        /** \fn void set_theme(Theme & th)
         *  \brief Sets active theme on display.
         *  \param th: theme object.
         */
        void set_theme(Theme & th);

        /** \fn Theme get_theme() const
         *  \brief Gets active theme.
         *  \returns theme object.
         */
        Theme get_theme() const;

        /** \brief Set state of display invalidation.
         *  \param en: if true, invalidation is enabled; if false, disabled.
         */
        void enable_invalidation(bool en);

        /** \brief Get state of display invalidation.
         *  \returns true if invalidation is enabled, false otherwise.
         */
        bool is_invalidation_enabled();

        /** \fn uint32_t get_inactive_time() const
         *  \brief Gets elapsed time since last activity.
         *  \returns elapsed time in ms.
         */
        uint32_t get_inactive_time() const;

        /** \fn void trig_activity()
         *  \brief Triggers activity on the display.
         * 
         *   Deprecated - use trigter_activity()
         */
        void trig_activity() { trigger_activity(); }

        /** \fn void trigger_activity()
         *  \brief Triggers activity on the display.
         */
        void trigger_activity();

    };

    // TODO: void lv_scr_load_anim(lv_obj_t * scr, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool auto_del);

    /** \fn void screen_load(Object & scr)
     *  \brief Sets active screen.
     *  \param scr: object representing a screen.
     */
    void screen_load(Object & scr);

    /** \fn void load_scr(Object & scr)
     *  \brief Sets active screen.
     *  \param scr: object representing a screen.
     *
     *   Deprecated - use screen_load()
     */
    void load_scr(Object & scr) { screen_load(scr); }

    /** \fn Object screen_active()
     *  \brief Gets the currently active screen.
     *  \returns object representing currently active screen.
     */
    Object screen_active();

    /** \fn Object scr_act()
     *  \brief Gets the currently active screen.
     *  \returns object representing currently active screen.
     *
     *  Deprecated - use screen_active
     */
    Object scr_act() { return screen_active(); }

    /** \fn Object layer_top()
     *  \brief Gets the currently active top layer.
     *  \returns object representing currently active top layer.
     */
    Object layer_top();

    /** \fn Object layer_sys()
     *  \brief Gets the currently active sys layer.
     *  \returns object representing currently active sys layer.
     */
    Object layer_sys();

}

