/** \file draw_buf.h
 *  \brief Header file for C++ wrapper for LVGL draw descriptors.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#pragma once

#include "../misc/color.h"
#include "image.h"

/** \namespace lvgl::draw
 *  \brief LVGL draw components.
 */
namespace lvgl::draw {
    
    using namespace lvgl::misc;
    using namespace lvgl::draw;

    class Layer;

    class DrawBuf : public PointerWrapper<lv_draw_buf_t, lv_free> {
    public:
        /** \fn  DrawBuf(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride,
         *               std::vector<uint8_t> & data)
         *  \brief : constructor taking external buffer
         *  \param w: Width
         *  \param h: height
         *  \param cf: colorformat   
         *  \param stride: stride (actual number of bytes horizontal)
         *  \param data: buffer for image data
         */
        DrawBuf(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride,
                std::vector<uint8_t> & data);

        /** \fn DrawBuf(const DrawBuf & other)
         *  \brief Copy constructer
         *  \param other: The DrawBuf to copy
         */
        DrawBuf(const DrawBuf & other);

        /** \fn DrawBuf(lv_draw_buf_t * lv_draw_buf)
         *  \brief Constructor taking native pointer
         *  \param lv_draw_buf: pointer to native lv_draw_buf_t object
         * 
         *  Nullptr not acceptable
         */
        DrawBuf(lv_draw_buf_t * lv_draw_buf);

        /** \fn DrawBuf create(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride)
         *  \brief Creator of DrawBuf object wiht internally allocated buffer
         *  \param w: width
         *  \param h: height
         *  \param cf: colorformat
         *  \param stride: stride (actual number of bytes horizontal)
         *  \return DrawBuf object
          */
        static DrawBuf create(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride);

        /** \fn uint32_t width_to_stride(uint32_t w, lv_color_format_t cf)
         *  \brief calculator of stride based on width and colorformat
         *  \param w: width
         *  \param cf: color format
         */
        static uint32_t width_to_stride(uint32_t w, lv_color_format_t cf);

        /** \fn void reshape(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride)
         *  \brief Reshapes draw buffer with new parameters - if space for it
         *  \param w: width
         *  \param h: height
         *  \param cf: color format
         *  \param stride: stride (actual number of bytes horizontal)
         */
        void reshape(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride);

        /** \fn void * goto_xy(uint32_t x, uint32_t y)
         *  \brief Finds address of specific point in buffer
         *  \param x: x coordinate
         *  \param y: y coordinate
         *  \return pointer to (x,y) point
        */
        void * goto_xy(uint32_t x, uint32_t y);

        /** \fn lv_result_t adjust_stride(uint32_t stride)
         *  \brief adjust stride 
         *  \param stride: new stride
         *  \return result of operation
         */
        lv_result_t adjust_stride(uint32_t stride);

        /** \fn lv_result_t premultiply()
         *  \brief Premultiply draw buffer color with alpha channel.
         *  \return result of operation
         */
        lv_result_t premultiply();

        /** \fn void set_palette(uint8_t index, lv_color32_t color)
         *  \brief set palette color
         *  \param index palette color to set
         *  \param color the color to set
         */
        void set_palette(uint8_t index, lv_color32_t color);

        /** \fn bool has_flag(lv_image_flags_t flag)
         *  \brief Check if flag is set
         *  \param flag: flag to test
         *  \return true if set, otherwise false
         */
        bool has_flag(lv_image_flags_t flag) const;

        /** \fn void set_flag(lv_image_flags_t flag)
         *  \brief sets a flag
         *  \param flag: flag to set
         */
        void set_flag(lv_image_flags_t flag);

        /** \fn void clear_flag(lv_image_flags_t flag)
         *  \brief clears a flag
         *  \param flag: flag to clear
         */
        void clear_flag(lv_image_flags_t flag);

        /** \fn lv_result_t from_image(const ImageDescriptor & img)
         *  \brief Update DrawBuf from image
         *  \param img: image to update from
         *  \return result of operation
         */
        lv_result_t from_image(const ImageDescriptor & img);

        /** \fn void to_image(ImageDescriptor & img)
         *  \brief Update image from DrawBuf
         *  \param img: image to update
         */
        void to_image(ImageDescriptor & img);

        /** \fn Area get_area()
         *  \brief get Area object from DrawBuf
         *  \return Area object of size (0,0, width, height)
         */
        Area get_area() const;
    };
}
