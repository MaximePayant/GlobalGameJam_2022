/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Mainchar.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_MAINCHAR_HPP
#define GGJ_2022_MAINCHAR_HPP

#include "SW/Component.hpp"

class MainChar: public sw::Component
{
    private:
        Shader m_shader;
        float* foo;
    public:
        explicit MainChar(sw::Entity& entity);
        ~MainChar() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_MAINCHAR_HPP
