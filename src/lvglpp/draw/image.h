/** \file image.h
 *  \brief Header file for C++ wrapper for low-level image-handling
 *  LVGL objects, such as lv_image_decoder_t, lv_image_header_t and lv_image_dsc_t.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once
#include "draw/lv_image_decoder_private.h"
#include "../misc/color.h"
#include "../misc/area.h"
#include "../lv_wrapper.h"
#include <vector>

namespace lvgl::draw {

    using namespace lvgl::misc;

    class ImageDescriptor;
    class ImageHeader;

    /** \class ImageDecoder
     *  \brief Wraps a lv_image_decoder_dsc_t object. This is a base class to decode
     *  an image format.
     */
    class ImageDecoder : public PointerWrapper<lv_image_decoder_dsc_t, lv_image_decoder_close> {
    protected:
        /** \fn virtual lv_res_t info_callback(struct _lv_img_decoder_t * decoder, const void * src, lv_image_header_t * header)
         *  \brief Callback to read image info.
         *  \param decoder: pointer to the underlying image decoder instance.
         *  \param src: a pointer to an data buffer or a file name.
         *  \param header: pointer to the recipient image header object.
         *  \returns result code.
         */
        virtual lv_res_t info_callback(struct _lv_img_decoder_t * decoder, const void * src, lv_image_header_t * header) = 0;

        /** \fn virtual lv_res_t open_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc)
         *  \brief Callback to open image.
         *  \param decoder: pointer to the underlying image decoder instance.
         *  \param dsc: a pointer to an image decoder descriptor.
         *  \returns result code.
         */
        virtual lv_res_t open_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc) = 0;

        /** \fn virtual lv_res_t read_line_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf)
         *  \brief Callback to read the image.
         *  \param decoder: pointer to the underlying image decoder instance.
         *  \param dsc: a pointer to an image decoder descriptor.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \param len: number of pixels to decode.
         *  \param buf: pointer to the recipient buffer.
         *  \returns result code.
         */
        virtual lv_res_t read_line_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf) = 0;

        /** \fn virtual lv_res_t close_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc)
         *  \brief Callback to close the image source.
         *  \param decoder: pointer to the underlying image decoder instance.
         *  \param dsc: a pointer to an image decoder descriptor.
         *  \returns result code.
         */
        virtual lv_res_t close_callback(struct _lv_img_decoder_t * decoder, lv_image_decoder_dsc_t * dsc) = 0;

    public:
        using PointerWrapper::PointerWrapper;

        /** \fn ImageDecoder(const ImageDescriptor & src, const lv_image_decoder_args_t * args)
         *  \brief Constructor with image source.
         *  \param src: image descriptor.
         *  \param args: decoder args
         */
        ImageDecoder(const ImageDescriptor & src, const lv_image_decoder_args_t * args);

        /** \fn static ImageHeader get_info(const ImageDescriptor & src)
         *  \brief Gets the image info.
         *  \param src: a pointer to an image buffer.
         *  \returns an image header instance.
         */
        static ImageHeader get_info(const ImageDescriptor & src);
        /** \fn static ImageHeader get_info(const std::string & src)
         *  \brief Gets the image info.
         *  \param src: file name or symbol name.
         *  \returns an image header instance.
         */
        static ImageHeader get_info(const std::string & src);

        /** \fn lv_res_t open(const ImageDescriptor & src, lv_color_t color, int32_t frame_id)
         *  \brief Opens an image.
         *  \param src: a pointer to an image buffer.
         *  \param color: background color.
         *  \param frame_id: index of the frame (for animated images).
         *  \returns result code.
         */
        lv_res_t open(const ImageDescriptor & src, lv_color_t color, int32_t frame_id);
        /** \fn lv_res_t open(const std::string & src, lv_color_t color, int32_t frame_id)
         *  \brief Opens an image.
         *  \param src: file name or symbol name.
         *  \param color: background color.
         *  \param frame_id: index of the frame (for animated images).
         *  \returns result code.
         */
        lv_res_t open(const std::string & src, lv_color_t color, int32_t frame_id);

#ifdef MISSING_PORT
        /** \fn lv_res_t read_line(lv_coord_t x, lv_coord_t y, lv_coord_t len, std::vector<uint8_t> & buf)
         *  \brief Reads one line from the opened image.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \param len: number of pixels to read.
         *  \param buf: pointer to target buffer.
         *  \returns result code.
         */
        lv_res_t read_line(lv_coord_t x, lv_coord_t y, lv_coord_t len, std::vector<uint8_t> & buf);
#endif

        /** \fn void close()
         *  \brief Closes the image source.
         */
        void close();

    };

    /** \class ImageHeader
     *  \brief Wraps a lv_image_header_t object.
     */
    class ImageHeader : public PointerWrapper<lv_image_header_t, lv_free> {
    private:
        /** \fn bool valid
         *  \brief True if header contains valid data, false otherwise.
         */
        bool valid = false;

    public:
        using PointerWrapper::PointerWrapper;

        /** \fn bool is_valid() const
         *  \brief Tells if header contains valid data.
         *  \returns true if header contains valid data, false otherwise.
         */
        bool is_valid() const;

        /** \fn is_valid(bool valid)
         *  \brief Sets if header contains valid data.
         *  \param valid: true if header contains valid data, false otherwise.
         */
        void is_valid(bool valid);

        Area area() const;
    };


    /** \class ImageDescriptor
     *  \brief Wraps a lv_image_decoder_dsc_t object.
     */
    class ImageDescriptor : public PointerWrapper<lv_image_dsc_t, lv_image_buf_free> {
    public:
        using PointerWrapper::PointerWrapper;

        ImageDescriptor();

        /** \fn ImageDescriptor(lv_coord_t w, lv_coord_t h, lv_color_format_t cf)
         *  \brief Constructor with parameters.
         *  \param w: buffer width.
         *  \param h: buffer height.
         *  \param cf: buffer color format.
         */
        ImageDescriptor(lv_coord_t w, lv_coord_t h, lv_color_format_t cf);

        /** \fn ImageDescriptor(const lv_img_dsc_t * dsc)
         *  \brief Construction with lv_img_dsc_t
         *  \param dsc: pointer to lv_img_dsc_t
         */
        ImageDescriptor(const lv_img_dsc_t * dsc);

 #ifdef MISSING_PORT
        /** \fn lv_color_t get_px_color(lv_coord_t x, lv_coord_t y, lv_color_t bg_color) const
         *  \brief Gets pixel color.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \param bg_color: background color.
         *  \returns pixel color blended with background color.
         */
        lv_color_t get_px_color(lv_coord_t x, lv_coord_t y, lv_color_t bg_color) const;

        /** \fn lv_opa_t get_px_alpha(lv_coord_t x, lv_coord_t y) const
         *  \brief Gets pixel opacity.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \returns pixel opacity.
         */
        lv_opa_t get_px_alpha(lv_coord_t x, lv_coord_t y) const;

        /** \fn void set_px_color(lv_coord_t x, lv_coord_t y, lv_color_t c)
         *  \brief Sets pixel color.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \param c: color.
         */
        void set_px_color(lv_coord_t x, lv_coord_t y, lv_color_t c);

        /** \fn void set_px_alpha(lv_coord_t x, lv_coord_t y, lv_opa_t opa)
         *  \brief Sets pixel opacity.
         *  \param x: horizontal coordinate.
         *  \param y: vertical coordinate.
         *  \param opa: opacity value.
         */
        void set_px_alpha(lv_coord_t x, lv_coord_t y, lv_opa_t opa);
#endif

        /** \fn void set_palette(uint8_t id, lv_color_t c)
         *  \brief Sets palette color.
         *  \param id: color index.
         *  \param c: color.
         */
        void set_palette(uint8_t id, lv_color_t c);

        /** \fn void set_palette(uint8_t id, lv_color32_t c)
         *  \brief Sets palette color.
         *  \param id: color index.
         *  \param c: color.
         */
        void set_palette(uint8_t id, lv_color32_t c);

 #ifdef MISSING_PORT
        /** \fn uint32_t get_img_size(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf) const
         *  \brief Computes image size in bytes.
         *  \param w: image width.
         *  \param h: image height.
         *  \param cf: color format.
         *  \returns image size in bytes.
         */
        uint32_t get_img_size(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf) const;
#endif

        /** \fn void set_src(const lv_image_dsc_t & dsc)
         *  \brief Sets image source.
         *  \param dsc: image descriptor
         */
        void set_src(const lv_image_dsc_t & dsc);

        /** \fn void set_src(const lv_image_dsc_t * dsc)
         *  \brief Sets image source.
         *  \param dsc: image descriptor
         */
        void set_src(const lv_image_dsc_t * dsc);
    };

}
