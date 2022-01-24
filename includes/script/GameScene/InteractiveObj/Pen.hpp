/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Pen.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __PEN_HPP__
#define __PEN_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Pen
    :   public InteractiveObj
{
    public:
        Pen(sw::Entity& entity);
        ~Pen() override = default;

        std::string type() const override { return ("Pen"); };

        void start();
        void update();

        void take() override {};

};

#endif // __PEN_HPP__