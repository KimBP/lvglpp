/** \file line.h
 *  \brief Header file for C++ wrapper for lv_line_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once
#include "../core/object.h"

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class Line
     *  \brief Wraps a lv_line_t object.
     */
    class Line : public Object {
    protected:
        /** \fn void initialize()
         *  \brief Initialize object.
         */
        void initialize() override;
        /** \fn void initialize(Object & parent)
         *  \brief Initialize object and assign parent object.
         *  \param parent: parent LVGL object.
         */
        void initialize(Object & parent) override;
    
    public:
        /** \fn Line()
         *  \brief Default constructor.
         */
        Line();
        /** \fn Line(Object & parent)
         *  \brief Constructor with parent object.
         *  \param parent: parent LVGL object.
         */
        Line(Object & parent);

        /** \fn void set_points(const std::vector<lv_point_t> points, uint16_t point_num)
         *  \brief Sets line points. Points array must remain allocated.
         *  \param points: array of points.
         *  \param point_num: number of points.
         */
        void set_points(const std::vector<lv_point_t> & points, uint16_t point_num);

        /** \fn void set_y_invert(bool en)
         *  \brief Sets vertical inversion.
         *  \param en: if true, vertical inversion is enabled.
         */
        void set_y_invert(bool en);

        /** \fn bool get_y_invert() const
         *  \brief Tells if vertical inversion is enabled.
         *  \returns true if vertical inversion is enabled, false otherwise.
         */
        bool get_y_invert() const;
    };

}
