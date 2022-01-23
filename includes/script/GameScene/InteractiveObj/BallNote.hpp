/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BallNote.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BALLNOTE_HPP__
#define __BALLNOTE_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class BallNote
    :   public InteractiveObj
{
    public:
        BallNote(sw::Entity& entity);
        ~BallNote() override = default;

        std::string type() const override { return ("BallNote"); };

        void start();
        void update();

        void interact() override {};

};

#endif // __BALLNOTE_HPP__