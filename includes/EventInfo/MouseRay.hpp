/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MouseRay.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __EVENTINFO_MOUSERAY_HPP__
#define __EVENTINFO_MOUSERAY_HPP__

#include "SW/Event.hpp"

class MouseRay_EventInfo
    :   public sw::IEventInfo
{

    public:
        MouseRay_EventInfo(int X, int Y, int Z)
            :   x{X},
                y{Y},
                z{Z}
        {}
        ~MouseRay_EventInfo() = default;

        int x;
        int y;
        int z;

};

#endif // __EVENTINFO_MOUSERAY_HPP__