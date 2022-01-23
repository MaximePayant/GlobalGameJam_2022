/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Box.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BOX_HPP__
#define __BOX_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Box
    :   public InteractiveObj
{
    public:
        Box(sw::Entity& entity);
        ~Box() override = default;

        std::string type() const override { return ("Box"); };

        void start();
        void update();

        void take() override {};
        void interact() override {};

};

#endif // __BOX_HPP__