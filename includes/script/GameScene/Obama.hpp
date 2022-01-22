/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Obama.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_OBAMA_HPP
#define GGJ_2022_OBAMA_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

class Obama: public sw::Component
{
    private:
        bool m_death;
        bool m_lastdeath;
        sw::Chrono m_time;
        enum {
            FADE_IN,
            STAY,
            FADE_OUT
        } m_state;

        void changeWorld();
    public:
        explicit Obama(sw::Entity& entity);
        ~Obama() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_OBAMA_HPP
