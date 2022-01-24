/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TextDisplay.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_TEXTDISPLAY_HPP
#define GGJ_2022_TEXTDISPLAY_HPP

#include "SW/Component.hpp"
#include "SW/Event.hpp"
#include "SW/Utils.hpp"

class TextDisplay: public sw::Component
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
        explicit TextDisplay(sw::Entity& entity);
        ~TextDisplay() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
        void showText(sw::EventInfo& info);
        void hideText();
};

#endif //GGJ_2022_TEXTDISPLAY_HPP
