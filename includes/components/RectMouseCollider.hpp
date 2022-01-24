/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectMouseCollider.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECTMOUSECOLLIDER_HPP__
#define __RECTMOUSECOLLIDER_HPP__

#include "SW/Component.hpp"
#include "SW/utils/Chrono.hpp"
#include "RAY/utils/Input.hpp"
#include "RectangleShape.hpp"

#include "RAYLIB/raylib.h"

class RectMouseCollider
    :   public sw::Component
{

    public:
        enum State { None, Hover, Lclick, Rclick };


    protected:
        State m_state;
        Rectangle m_rect;
        sw::Chrono m_clock;
        RectangleShape m_shape;

    public:
        RectMouseCollider(sw::Entity& entity, const sw::Vector2f& pos, const sw::Vector2f& size);
        //RectMouseCollider(sw::Entity& entity, int left, int top, int width, int height);
        virtual ~RectMouseCollider() = default;

        State state() const { return (m_state); }
        State state(State value) { m_state = value; return (m_state); }
        void startClock() { m_clock.start(); }
        double clock() { return (m_clock.getElapsedTime()); }

        bool checkCollision(sw::Vector2f& point);

        void leftClickPressed_Event(sw::EventInfo& info);
        void leftClickReleased_Event();
        void rightClickPressed_Event(sw::EventInfo& info);
        void rightClickReleased_Event();

        virtual void onLeftClick() {};
        virtual void onRightClick() {};

        virtual void onLeftRelease() {};
        virtual void onRightRelease() {};

        virtual void onHover() {};
        virtual void onNormal() {};

        const RectangleShape& shape() const { return (m_shape); }
        std::string type() const override { return ("RectMouseCollider"); }

};

#endif // __RECTMOUSECOLLIDER_HPP__