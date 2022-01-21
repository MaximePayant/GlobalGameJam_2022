/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MousePosition.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __EVENTINFO_MOUSEPOSITION_HPP__
#define __EVENTINFO_MOUSEPOSITION_HPP__

#include "SW/Event.hpp"

class MousePosition_EventInfo
    :   public sw::IEventInfo
{

    public:
        MousePosition_EventInfo(int X, int Y)
            :   x{X},
                y{Y}
        {}
        ~MousePosition_EventInfo() = default;

        int x;
        int y;

};

#endif // __EVENTINFO_MOUSEPOSITION_HPP__