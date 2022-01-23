/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Note.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __NOTE_HPP__
#define __NOTE_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class Note
    :   public InteractiveObj
{
    public:
        Note(sw::Entity& entity);
        ~Note() override = default;

        std::string type() const override { return ("Note"); };

        void start();
        void update();

};

#endif // __NOTE_HPP__