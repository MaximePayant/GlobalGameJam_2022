/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * SimpleNote.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SIMPLENOTE_HPP__
#define __SIMPLENOTE_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class SimpleNote
    :   public InteractiveObj
{
    public:
        SimpleNote(sw::Entity& entity);
        ~SimpleNote() override = default;

        std::string type() const override { return ("SimpleNote"); };

        void start();
        void update();

};

#endif // __SIMPLENOTE_HPP__