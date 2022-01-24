/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Pillow.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __PILLOW_HPP__
#define __PILLOW_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Pillow
    :   public InteractiveObj
{

    public:
        Pillow(sw::Entity& entity);
        ~Pillow() override = default;

        std::string type() const override { return ("Pillow"); };

        void start();
        void update();

        void interact() override;

};

#endif // __PILLOW_HPP__