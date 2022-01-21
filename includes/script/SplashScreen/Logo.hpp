/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Logo.hpp
** Description: [CHANGE]
*/

#ifndef BOMBERSHIP_LOGO_HPP
#define BOMBERSHIP_LOGO_HPP

#include "SW/Component.hpp"

class Logo : public sw::Component
{
    private:
        enum {
            FADE_IN,
            STAY,
            FADE_OUT
        } m_state;
    public:
        explicit Logo(sw::Entity& entity);
        ~Logo() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //BOMBERSHIP_LOGO_HPP
