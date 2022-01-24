/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Ghost2.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_GHOST2_HPP
#define GGJ_2022_GHOST2_HPP

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"

class Ghost2: public sw::Component
{
    private:
        Shader m_shader;
        float* foo;
    public:
        explicit Ghost2(sw::Entity& entity);
        ~Ghost2() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_GHOST1_HPP
