/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * PoemeFrag1.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __POEMEFRAG1_HPP__
#define __POEMEFRAG1_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class PoemeFrag1
    :   public InteractiveObj
{
    public:
        PoemeFrag1(sw::Entity& entity);
        ~PoemeFrag1() override = default;

        std::string type() const override { return ("PoemeFrag1"); };

        void start();
        void update();

};

#endif // __POEMEFRAG1_HPP__