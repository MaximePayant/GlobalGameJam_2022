/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Ball.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Ball
    :   public InteractiveObj
{
    public:
        Ball(sw::Entity& entity);
        ~Ball() override = default;

        std::string type() const override { return ("Ball"); };

        void start();
        void update();

        void take() override;
        void interact() override;

};

#endif // __BALL_HPP__