/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ButtonTest.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BUTTONTEST_HPP__
#define __BUTTONTEST_HPP__

#include "RectMouseCollider.hpp"

class Button
    :   public RectMouseCollider
{

    public:
        using RectMouseCollider::RectMouseCollider;
        ~Button() = default;

        void onLeftClick() override
        {
            sw::Speech::Debug("Left Click");
            m_shape.setOutlineColor(ray::Green);
        }
        void onRightClick() override
        {
            sw::Speech::Debug("Right Click");
            m_shape.setOutlineColor(ray::Purple);
        }

        void onLeftRelease() override
        {
            sw::Speech::Debug("Left Release");
            m_shape.setOutlineColor(ray::Blue);
        }
        void onRightRelease() override
        {
            sw::Speech::Debug("Right Release");
            m_shape.setOutlineColor(ray::Blue);
        }

        void onHover() override
        {
            sw::Speech::Debug("Hover");
            m_shape.setOutlineColor(ray::Blue);
        }
        void onNormal() override
        {
            sw::Speech::Debug("Normal");
            m_shape.setOutlineColor(ray::Red);
        }

};

#endif // __BUTTONTEST_HPP__