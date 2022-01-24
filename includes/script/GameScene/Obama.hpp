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

#include "RAYLIB/raylib.h"
#define RLIGHTS_IMPLEMENTATION
#include "RAYLIB/rlight.h"

class Obama: public sw::Component
{
    private:
        bool m_death;
        bool m_lastdeath;
        sw::Chrono m_time;
        sw::Chrono m_blink;
        enum {
            FADE_IN,
            STAY,
            FADE_OUT
        } m_state;
        Shader m_shader;
        Light m_light;
        Light m_direct;
        float *foo;

        void changeWorld();
    public:
        explicit Obama(sw::Entity& entity);
        ~Obama() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();

        void changeWorldEvent();
};

#endif //GGJ_2022_OBAMA_HPP
