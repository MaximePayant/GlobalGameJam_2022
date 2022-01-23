/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Ghost1.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_GHOST1_HPP
#define GGJ_2022_GHOST1_HPP

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"

class Ghost1: public sw::Component
{
    private:
        Shader m_shader;
        float* foo;
    public:
        explicit Ghost1(sw::Entity& entity);
        ~Ghost1() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_GHOST1_HPP
