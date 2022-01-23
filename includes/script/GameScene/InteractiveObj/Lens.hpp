/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Lens.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __LENS_HPP__
#define __LENS_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Lens
    :   public InteractiveObj
{
    public:
        Lens(sw::Entity& entity);
        ~Lens() override = default;

        std::string type() const override { return ("Lens"); };

        void start();
        void update();

        void take() override;

};

#endif // __LENS_HPP__