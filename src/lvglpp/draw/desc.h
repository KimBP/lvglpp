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
    using namespace lvgl::draw;

    class Layer;

    /** \class BaseDrawDescriptor
     *  \brief Wraps the lv_draw_dsc_base_t struct
     */
    class BaseDrawDescriptor : public PointerWrapper<lv_draw_dsc_base_t, lv_free> {
    public:
        /** \fn BaseDrawDescriptor(lv_draw_dsc_base_t * descriptor)
         *  \brief Constructor taking a native descriptor
         *  \param descriptor: Any native draw descriptor correctly typecasted
         */
        BaseDrawDescriptor(lv_draw_dsc_base_t * descriptor);

        /** \fn lv_part_t part()
         *  \brief Returns part member of native object
         *  \return part
         */
        lv_part_t part();

        /** \fn uint32_t id1()
         *  \brief Returns id1 member of native object
         *  \return id1
         */
        uint32_t id1();

        /** \fn uint32_t id2()
         *  \brief Returns id2 member of native object
         *  \return id2
         */
        uint32_t id2();

        /** \fn Layer layer()
         *  \brief Returns layer member of native object
         *  \return layer as class Layer object
         */
        Layer layer();
    };

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
         *  \brief Draws a rectangle using a draw layer.
         *  \param layer: layer
         *  \param coords: rectangle coordinates.
         */
        void draw(Layer & layer, const Area & coords);
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

        /** \fn LabelDrawDescriptor(lv_draw_label_dsc_t * descriptor)
         *  \brief Constructor taking native object.
         *  \param descriptor native label descriptor
         *
         *  Undetermined if descriptor is not of type lv_draw_label_dsc_t
         */
        LabelDrawDescriptor(lv_draw_label_dsc_t * descriptor);

        /** \fn void draw(Layer & layer, const Area & coords)
         *  \brief Draws a text using a draw layer.
         *  \param layer: layer.
         *  \param coords: area where to draw.
         */
        void draw(Layer & layer, const Area & coords);
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

        /** \fn void draw(Layer & layer, const lv_point_t & pos)
         *  \brief Draws a letter using a draw layer.
         *  \param layer: layer.
         *  \param pos: position.
         */
        void draw(Layer & layer, const lv_point_t & pos);
    };

    /** \class ImageDrawDescriptor
     *  \brief Wraps a lv_draw_img_dsc_t object.
     */
    class ImageDrawDescriptor : public PointerWrapper<lv_draw_image_dsc_t, lv_free> {
    public:
        /** \fn ImageDrawDescriptor()
         *  \brief Default constructor.
         */
        ImageDrawDescriptor();

        /** \fn void draw(Layer & layer, const Area & coords)
         *  \brief Draws an image using a draw layer.
         *  \param layer: layer.
         *  \param coords: area where to draw.
         */
        void draw(Layer & layer, const Area & coords);
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

        /** \fn void draw(Layer & layer)
         *  \brief Draws an line using a draw layer.
         *  \param layer: layer
         */
        void draw(Layer & layer);
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

        /** \fn void draw(Layer & layer)
         *  \brief Draws an arc using a draw layer
         *  \param layer: layer
         */
        void draw(Layer & layer);
    };

    /** \class FillDrawDescriptor
     *  \brief Wraps a lv_draw_fill_dsc_t object.
     */
    class FillDrawDescriptor : public PointerWrapper<lv_draw_fill_dsc_t, lv_free> {
    public:
        /** \fn FillDrawDescriptor()
         *  \brief Default constructor.
         */
        FillDrawDescriptor();

        /** \fn FillDrawDescriptor(lv_draw_fill_dsc_t * descriptor)
         *  \brief Constructor taking native object.
         *  \param descriptor native fill descriptor
         *
         *  Undetermined if descriptor is not of type lv_draw_fill_dsc_t
         */
        FillDrawDescriptor(lv_draw_fill_dsc_t * descriptor);

        /** \fn void draw(Layer & layer, const Area & coords)
         *  \brief Draws an fill using layer
         */
        void draw(Layer & layer, const Area & coords);
    };

    /** \class BoxShadowDrawDescriptor
     *  \brief Wraps a lv_draw_box_shadow_dsc_t object.
     */
    class BoxShadowDrawDescriptor : public PointerWrapper<lv_draw_box_shadow_dsc_t, lv_free> {
    public:
        /** \fn BoxShadowDrawDescriptor()
         *  \brief Default constructor.
         */
        BoxShadowDrawDescriptor();

        /** \fn BoxShadowDrawDescriptor(lv_draw_box_shadow_dsc_t * descriptor)
         *  \brief construct taking native object
         *  \param descriptor native box_shadow descriptor
         *
         *  Undetermined if descriptor is not of type lv_draw_box_shadow_dsc_t
         */
        BoxShadowDrawDescriptor(lv_draw_box_shadow_dsc_t * descriptor);

        /** \fn void draw(Layer & layer, const Area & coords)
         *  \brief Draws a box shadow using layer
         */
        void draw(Layer & layer, const Area & coords);
    };
}
