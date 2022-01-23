/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TextBox.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_TEXTBOX_HPP
#define GGJ_2022_TEXTBOX_HPP

#include "SW/Component.hpp"
#include "SW/Event.hpp"
#include "SW/Utils.hpp"

class TextBox: public sw::Component
{
    private:
        enum {
            SHOW,
            STAY
        } m_state;
        sw::Chrono m_time;
        std::string m_save;
        unsigned int m_nbr;

    public:
        explicit TextBox(sw::Entity& entity);
        ~TextBox() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
        void showText(sw::EventInfo& info);
        void hideText();
};

#endif //GGJ_2022_TEXTBOX_HPP
