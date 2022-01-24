/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Hook.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __HOOK_HPP__
#define __HOOK_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Hook
    :   public InteractiveObj
{
    public:
        Hook(sw::Entity& entity);
        ~Hook() override = default;

        std::string type() const override { return ("Hook"); };

        void start();
        void update();

};

#endif // __HOOK_HPP__