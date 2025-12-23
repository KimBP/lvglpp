/** \file layer.h
 *  \brief Header file for C++ wrapper for layer routines.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#pragma once
#include "../misc/area.h"
#include "../lv_wrapper.h"
#include "desc.h"
#include "../core/display.h"
#include <type_traits>
#include <concepts> // For C++20 concepts

namespace lvgl::draw {

    using namespace lvgl::core;
    using namespace lvgl::misc;

    template <typename T>
    concept IsValidDrawDescriptor = std::is_same<T, RectangleDrawDescriptor>::value ||
                                    std::is_same<T, LabelDrawDescriptor>::value ||
                                    std::is_same<T, LetterDrawDescriptor>::value ||
                                    std::is_same<T, ImageDrawDescriptor>::value ||
                                    std::is_same<T, LineDrawDescriptor>::value ||
                                    std::is_same<T, ArcDrawDescriptor>::value ||
                                    std::is_same<T, FillDrawDescriptor>::value ||
                                    std::is_same<T, BoxShadowDrawDescriptor>::value;

    template <IsValidDrawDescriptor T>
    lv_draw_task_type_t getDrawTaskType(T & descriptor) {
        if constexpr (std::is_same<T, RectangleDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_MASK_RECTANGLE;
        } else if constexpr (std::is_same<T, LabelDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_LABEL;
        } else if constexpr (std::is_same<T, LetterDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_LETTER;
        } else if constexpr (std::is_same<T, ImageDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_IMAGE;
        } else if constexpr (std::is_same<T, LineDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_LINE;
        } else if constexpr (std::is_same<T, ArcDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_ARC;
        } else if constexpr (std::is_same<T, FillDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_FILL;
        } else if constexpr (std::is_same<T, BoxShadowDrawDescriptor>::value) {
            return LV_DRAW_TASK_TYPE_BOX_SHADOW;
        }
    }

    template<typename T>
    struct DescTraits {
        // assert(0);
    };

    template<>
    struct DescTraits<LabelDrawDescriptor> {
        using desc_pointer_type = lv_draw_label_dsc_t*;
        static constexpr lv_draw_task_type_t descriptor_type = LV_DRAW_TASK_TYPE_LABEL;
    };

    template<>
    struct DescTraits<FillDrawDescriptor> {
        using desc_pointer_type = lv_draw_fill_dsc_t*;
        static constexpr lv_draw_task_type_t descriptor_type = LV_DRAW_TASK_TYPE_FILL;
    };

    template<>
    struct DescTraits<BoxShadowDrawDescriptor> {
        using desc_pointer_type = lv_draw_box_shadow_dsc_t*;
        static constexpr lv_draw_task_type_t descriptor_type = LV_DRAW_TASK_TYPE_BOX_SHADOW;
    };

    class DrawTask : public PointerWrapper<lv_draw_task_t, lv_free> {

    public:
        DrawTask() = delete;
        DrawTask(const DrawTask&) = delete;
        DrawTask & operator=(const DrawTask&) = delete;

        DrawTask(lv_draw_task_t * draw_task) {
            this->owns_ptr = false;
            this->lv_obj = LvPointer<lv_draw_task_t, lv_free>(draw_task);
        }

        uint32_t get_dependent_count() {
            return lv_draw_get_dependent_count(this->raw_ptr());
        }

        lv_draw_task_type_t get_type() {
            return lv_draw_task_get_type(this->raw_ptr());
        }

        template<IsValidDrawDescriptor T>
        std::unique_ptr<T> get_draw_descriptor() {
            const lv_draw_task_type_t expected_type = DescTraits<T>::descriptor_type;

            if (get_type() != expected_type) {
                return nullptr;
            }

            using desc_pointer_type = typename DescTraits<T>::desc_pointer_type;

            return std::make_unique<T>(
                        reinterpret_cast<desc_pointer_type>(this->raw_ptr()->draw_dsc));
        }

        std::unique_ptr<BaseDrawDescriptor> getBaseDescriptor() {
            return std::make_unique<BaseDrawDescriptor>(
                reinterpret_cast<lv_draw_dsc_base_t * >(this->raw_ptr()->draw_dsc)
            );
        }

        Area get_area() {
            lv_area_t area;
            lv_draw_task_get_area(this->raw_ptr(), &area);

            return Area(area);
        }
    };

    class Layer : public PointerWrapper<lv_layer_t, lv_free> {
    public:
        /** \fn Default construct
         *  \brief Only allocates memory. Initialization must be handled by creator
         *  
         *  See e.g. lv_canvas_init_layer()
         */
        Layer();

        // no copy constructor and copy assignment operator
        Layer(const Layer&) = delete;
        Layer & operator=(const Layer &) = delete;

        /** \fn Layer(lv_color_format_t cf, const Area & area)
         *  \brief Constructor taking arguments
         *  \param cf: Color format
         *  \param area: Area of layer
         */
        Layer(lv_color_format_t cf, const Area & area);

        /** \fn Layer(Layer & parent, lv_color_format_t cf, const Area & area)
         *  \brief Constructor taking arguments
         *  \param parent: - parent object
         *  \param cf: Color format
         *  \param area: Area of layer
         */
        Layer(Layer & parent, lv_color_format_t cf, const Area & area);

        /** \fn Layer(lv_layer_t * layer)
         *  \brief Constructor taking native object
         *  \param layer: native lvgl object
         * 
         *  Outght maybe be protected
         */
        Layer(lv_layer_t * layer);

        /** \fn reset()
         *  \brief resets layer
         */
        void reset();

        /** \fn go_to_xy(int32_t x, int32_t y)
         *  \brief gives pointer to point in layer
         *  \param x: x coordinate
         *  \param y: y coordinate
         */
        void * go_to_xy(int32_t x, int32_t y);

        /** \fn bool dispatch(Display & display)
         *  \brief attemp to dispatch at least one layer
         *  \param display: Display to render at
         *  \return true if at least one layer was rendered
         */
        bool dispatch(Display & display);

        /** \fn DrawTask get_available_task(uint8_t draw_unit_id)
         *  \brief get task based on unit id
         *  \param draw_unit_id unit id to search for or LV_DRAW_UNIT_NONE
         *  \return DrawTask if any found
         */
        DrawTask get_available_task(uint8_t draw_unit_id);


        /** \fn DrawTask get_available_task(DrawTask & prev, uint8_t draw_unit_id)
         *  \brief get next task based on unit id
         *  \param prev Previous DrawTask found
         *  \param draw_unit_id unit id to search for or LV_DRAW_UNIT_NONE
         *  \return DrawTask if any found
         */
        DrawTask get_available_task(DrawTask & prev, uint8_t draw_unit_id);


        /** \fn DrawTask get_next_available_task(uint8_t draw_unit_id)
         *  \brief get task based on unit id
         *  \param draw_unit_id unit id to search for or LV_DRAW_UNIT_NONE
         *  \return DrawTask if any found
         */
        DrawTask get_next_available_task(uint8_t draw_unit_id);

        /** \fn DrawTask get_next_available_task(DrawTask & prev, uint8_t draw_unit_id)
         *  \brief get next task based on unit id
         *  \param prev Previous DrawTask found
         *  \param draw_unit_id unit id to search for or LV_DRAW_UNIT_NONE
         *  \return DrawTask if any found
         */
        DrawTask get_next_available_task(DrawTask & prev, uint8_t draw_unit_id);

        /** \fn add_task<>(const Area & area, T & descriptor)
         *  \brief adds a task (template type) to layer
         *  \param area: Area to add task to
         *  \param descriptor: DrawTask descriptor to add
         */
        template<IsValidDrawDescriptor T>
        void add_task(const Area & area, T & descriptor) {
            auto taskType = getDrawTaskType(descriptor);

            auto drawTask = lv_draw_add_task(this->raw_ptr(), area.raw_ptr(), taskType);
            lv_memcpy(drawTask->dsc, descriptor->raw_ptr(), sizeof(*descriptor->raw_ptr()));
            finalize_task_creation(drawTask);
        }

        /** \fn DrawTask add_task(const Area & area, lv_draw_task_type_t taskType)
         *  \brief creates a new task on layer
         *  \param area: Area to add task to
         *  \param taskType: type of task to add
         *  \return DrawTask of specififed type
         */
        DrawTask add_task(const Area & area, lv_draw_task_type_t taskType);

        /** \fn void finalize_task_creation(DrawTask & drawTask)
         *  \brief signals that a new task is ready to be processed. 
         *  \param drawTask: the newly added and fully configured task
         */
        void finalize_task_creation(DrawTask & drawTask);
    };
}
