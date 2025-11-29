/** \file desc.h
 *  \brief Header file for C++ wrapper for LVGL draw descriptors.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once
#include "../misc/area.h"
#include "../misc/color.h"
#include "../font/font.h"
#include "image.h"

/** \namespace lvgl::draw
 *  \brief LVGL draw components.
 */
namespace lvgl::draw {
    
    using namespace lvgl::misc;
    using namespace lvgl::font;

    /** \class RectangleDrawDescriptor
     *  \brief Wraps a lv_draw_rect_dsc_t object.
     */
    class RectangleDrawDescriptor : public PointerWrapper<lv_draw_rect_dsc_t, lv_free> {
    public:
        /** \fn RectangleDrawDescriptor()
         *  \brief Default constructor.
         */
        RectangleDrawDescriptor();

        /** \fn void draw(lv_draw_ctx_t * draw_ctx, const Area & coords)
         *  \brief Draws a rectangle using a draw context.
         *  \param draw_ctx: draw context.
         *  \param coords: rectangle coordinates.
         */
        void draw(lv_layer_t * draw_ctx, const Area & coords);

    };


    /** \class LabelDrawDescriptor
     *  \brief Wraps a lv_draw_label_dsc_t object.
     */
    class LabelDrawDescriptor : public PointerWrapper<lv_draw_label_dsc_t, lv_free> {
    public:
        /** \fn LabelDrawDescriptor()
         *  \brief Default constructor.
         */
        LabelDrawDescriptor();

        /** \fn void draw(lv_draw_ctx_t * ctx, const Area & coords)
         *  \brief Draws a text using a draw context.
         *  \param ctx: draw context.
         *  \param coords: area where to draw.
         */
        void draw(lv_layer_t * ctx, const Area & coords);

    };

    /** \class LetterDrawDescriptor
     *  \brief Wraps a lv_draw_letter_dsc_t object.
     */
    class LetterDrawDescriptor : public PointerWrapper<lv_draw_letter_dsc_t, lv_free> {
    public:
        /** \fn LetterDrawDescriptor()
         *  \brief Default constructor.
         */
        LetterDrawDescriptor();

        /** \fn void draw_letter(lv_draw_ctx_t * ctx, const lv_point_t & pos)
         *  \brief Draws a letter using a draw context.
         *  \param ctx: draw context.
         *  \param pos: position.
         */
        void draw_letter(lv_layer_t * ctx, const lv_point_t & pos);

    };


    /** \class ImageDrawDescriptor
     *  \brief Wraps a lv_draw_img_dsc_t object.
     */
    class ImageDrawDescriptor : public PointerWrapper<lv_draw_image_dsc_t, lv_free> {
    public:
        ImageDrawDescriptor();

        /** \fn void draw(lv_draw_ctx_t * ctx, const Area & coords)
         *  \brief Draws an image using a draw context.
         *  \param ctx: draw context.
         *  \param coords: area where to draw.
         */
        void draw(lv_layer_t * ctx, const Area & coords);
        // TODO: void draw_decoded
    };

    /** \class LineDrawDescriptor
     *  \brief Wraps a lv_draw_line_dsc_t object.
     */
    class LineDrawDescriptor : public PointerWrapper<lv_draw_line_dsc_t, lv_free> {
    public:
        /** \fn LineDrawDescriptor()
         *  \brief Default constructor.
         */
        LineDrawDescriptor();

        /** \fn void draw(lv_draw_ctx_t * ctx)
         *  \brief Draws an line using a draw context.
         *  \param ctx: draw context.
         */
        void draw(lv_layer_t * ctx);
    };

    /** \class ArcDrawDescriptor
     *  \brief Wraps a lv_draw_arc_dsc_t object.
     */
    class ArcDrawDescriptor : public PointerWrapper<lv_draw_arc_dsc_t, lv_free> {
    public:
        /** \fn ArcDrawDescriptor()
         *  \brief Default constructor.
         */
        ArcDrawDescriptor();

        /** \fn void draw(lv_draw_ctx_t * ctx)
         *  \brief Draws an arc using a draw context.
         *  \param ctx: draw context.
         */
        void draw(lv_layer_t * ctx);
    };

}
