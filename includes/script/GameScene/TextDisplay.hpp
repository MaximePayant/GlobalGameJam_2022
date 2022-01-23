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

class TextDisplay: public sw::Component
{
    public:
        explicit TextDisplay(sw::Entity& entity);
        ~TextDisplay() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_TEXTDISPLAY_HPP
