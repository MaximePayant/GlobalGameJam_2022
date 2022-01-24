/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BreashWall.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BREASHWALL_HPP__
#define __BREASHWALL_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class BreashWall
    :   public InteractiveObj
{
    public:
        BreashWall(sw::Entity& entity);
        ~BreashWall() override = default;

        std::string type() const override { return ("BreashWall"); };

        void start();
        void update();

        void interact() override {};

};

#endif // __BREASHWALL_HPP__