/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Poster.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __Poster_HPP__
#define __Poster_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Poster
    :   public InteractiveObj
{
    public:
        Poster(sw::Entity& entity);
        ~Poster() override = default;

        std::string type() const override { return ("Poster"); };

        void start();
        void update();

        void interact() override {};

};

#endif // __Poster_HPP__