/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * PoemeFrag2.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __POEMEFRAG2_HPP__
#define __POEMEFRAG2_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class PoemeFrag2
    :   public InteractiveObj
{
    public:
        PoemeFrag2(sw::Entity& entity);
        ~PoemeFrag2() override = default;

        std::string type() const override { return ("PoemeFrag2"); };

        void start();
        void update();

};

#endif // __POEMEFRAG2_HPP__