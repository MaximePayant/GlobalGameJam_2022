/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * InteractiveObj.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __INTERACTIVEOBJ_HPP__
#define __INTERACTIVEOBJ_HPP__

#include "SW/Component.hpp"

class InteractiveObj
    :   public sw::Component
{

    public:
        enum State {
            Placed,
            Taked,
            Opened,
            Closed
        } m_state;

        InteractiveObj(sw::Entity& entity)
            :   sw::Component{entity},
                m_state{Placed}
        {}
        ~InteractiveObj() = default;

        virtual void take() {};
        virtual void interact() {};

};

#endif // __INTERACTIVEOBJ_HPP__