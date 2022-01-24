/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AlarmClock.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __ALARMCLOCK_HPP__
#define __ALARMCLOCK_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "InteractiveObj.hpp"

class AlarmClock
    :   public InteractiveObj
{

    public:
        AlarmClock(sw::Entity& entity);
        ~AlarmClock() override = default;

        std::string type() const override { return ("AlarmClock"); };

        void start();
        void update();

        void interact() override;

};

#endif // __ALARMCLOCK_HPP__