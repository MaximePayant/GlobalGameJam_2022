/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Package.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Package
    :   public InteractiveObj
{
    public:
        Package(sw::Entity& entity);
        ~Package() override = default;

        std::string type() const override { return ("Package"); };

        void start();
        void update();

        void interact() override;

};

#endif // __PACKAGE_HPP__