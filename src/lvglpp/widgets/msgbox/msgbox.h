/** \file msgbox.h
 *  \brief Header file for C++ wrapper for lv_msgbox_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"
#include <string>
#include <vector>

#if LV_USE_MSGBOX

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class MessageBox
     *  \brief Wraps a lv_msgbox_t object.
     */
    class MessageBox : public Object {
    private:
        /** \property RawDblArray<char> btn_txts
         *  \brief Button texts.
         */
        RawDblArray<char> btn_txts;

    protected:
        /** \fn void initialize(const std::string & title, const std::string & txt,
         *                      const std::vector<std::string> & btn_txts,
         *                      bool add_close_btn)
         *  \brief Initialize object with parameters.
         *  \param title: message box title.
         *  \param txt: message box text.
         *  \param btn_txts: button texts.
         *  \param add_close_btn: if true, adds a close button.
         */
        void initialize(const std::string & title, const std::string & txt,
                        const std::vector<std::string> & btn_txts,
                        bool add_close_btn);
    
    public:
        using Object::Object;

        /** \fn MessageBox()
         *  \brief Default constructor
         */
        MessageBox() : MessageBox(nullptr) {};

        /** \fn MessageBox(Object & parent)
         *  \brief Consructor with parent object.
         *  \param parent: parent LVGL object.
         */
        MessageBox(Object & parent);

        /** \fn MessageBox(const std::string & title, const std::string & txt,
         *                 const std::vector<std::string> & btn_txts,
         *                 bool add_close_btn)
         *  \brief Constructor with parameters.
         *  \param title: message box title.
         *  \param txt: message box text.
         *  \param btn_txts: button texts.
         *  \param add_close_btn: if true, adds a close button.
         */
        MessageBox(const std::string & title, const std::string & txt,
                   const std::vector<std::string> & btn_txts,
                   bool add_close_btn);

        /** \fn MessageBox(Object & parent, const std::string & title,
         *                 const std::string & txt, const std::vector<std::string> & btn_txts,
         *                 bool add_close_btn)
         *  \brief Constructor with parameters and parent object.
         *  \param parent: parent LVGL object.
         *  \param title: message box title.
         *  \param txt: message box text.
         *  \param btn_txts: button texts.
         *  \param add_close_btn: if true, adds a close button.
         */
        MessageBox(Object & parent, const std::string & title, const std::string & txt,
                   const std::vector<std::string> & btn_txts,
                   bool add_close_btn);

        /** \fn Object add_title(const std::string & title)
         *  \brief Add title to messagebox
         *  \param title: message box title
         *  \returns object for title element
         */
        Object add_title(const std::string & title);

        /** \fn Object add_header_button(const void* icon)
         *  \brief Add a button to header
         *  \param icon: The icon identifying the button
         *  \returns object for button element
         */
        Object add_header_button(const void* icon);

        /** \fn Object add_text(const std::string & text)
         *  \brief Adds message box text
         *  \param text: message box text
         *  \returns object for text element
         */
        Object add_text(const std::string & text);

        /** \fn Object add_footer_button(const std::string & text)
         *  \brief Adds message box footer button
         *  \param text: button text
         *  \returns object for text element
         */
        Object add_footer_button(const std::string & text);

        /** \fn Object add_close_button()
         *  \brief Adds close button in header
         *  \returns object for button
         */
        Object add_close_button();

        /** \fn Object get_title() const
         *  \brief Gets object for title element.
         *  \returns object for title element.
         */
        Object get_title() const;

#ifdef MISSING_PORT
        /** \fn Object get_close_btn() const
         *  \brief Gets object for close button.
         *  \returns object for close button.
         */
        Object get_close_btn() const;

        /** \fn Object get_text() const
         *  \brief Gets object for text.
         *  \returns object for text.
         */
        Object get_text() const;
#endif

        /** \fn Object get_content() const
         *  \brief Gets object for content.
         *  \returns object for content.
         *
         *   Content contains text label and footer
         */
        Object get_content() const;

        /** \fn Object get_footer() const
         *  \brief Gets object for footer.
         *  \returns object for footer.
         *
         *   footer contains buttons
         */
        Object get_footer() const;

        /** \fn Object get_btns() const
         *  \brief Gets object for buttons.
         *  \returns object for buttons (aka footer)
         *
         *  Function deprecated
         */
        Object get_btns() const { return get_footer(); };

 #ifdef MISSING_PORT
        /** \fn uint16_t get_active_btn() const
         *  \brief Gets active button.
         *  \returns active button index.
         */
        uint16_t get_active_btn() const;

        /** \fn std::string get_active_btn_text() const
         *  \brief Gets active button text.
         *  \returns active button text string.
         */
        std::string get_active_btn_text() const;
#endif

        /** \fn void close()
         *  \brief Closes message box.
         */
        void close();

        /** \fn void close_async()
         *  \brief Closes message box asynchronously.
         */
        void close_async();
    };

}
#endif // LV_USE_MSGBOX