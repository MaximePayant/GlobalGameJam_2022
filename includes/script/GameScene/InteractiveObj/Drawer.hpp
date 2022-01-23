/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Drawer.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __DRAWER_HPP__
#define __DRAWER_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Drawer
    :   public InteractiveObj
{
    public:
        Drawer(sw::Entity& entity);
        ~Drawer() override = default;

        std::string type() const override { return ("Drawer"); };

        void start();
        void update();

        void interact() override;

};

#endif // __DRAWER_HPP__