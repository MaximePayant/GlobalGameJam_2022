/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ObjCollider.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __OBJCOLLIDER_HPP__
#define __OBJCOLLIDER_HPP__

#include "RAY/components/Collider.hpp"
#include "RAY/utils/Color.hpp"

class ObjCollider
    :   public ray::CubeCollider
{

    public:
        enum State { None, Hover, Click };

    private:
        State m_state;
        Color m_color;

    public:
        ObjCollider(sw::Entity& entity);
        ObjCollider(sw::Entity& entity, const ::Vector3& size);
        ObjCollider(sw::Entity& entity, const ::Vector3& origin, const ::Vector3& size);
        ~ObjCollider() = default;

        State state() const { return (m_state); }
        State state(State value) { m_state = value; return (m_state); }

        Color color() const { return (m_color); }
        Color color(Color value) { m_color = value; return (m_color); }

        void leftClickPressed_Event(sw::EventInfo& info);
        void leftClickReleased_Event();

        void onEnterCollide() {
            color(ray::Blue.getColor());
        };
        void onQuitCollide() {
            color(ray::Green.getColor());
        };

        void onClick() {
            color(ray::Yellow.getColor());
        };
        void onRelease() {
            color(ray::Blue.getColor());
        };

};

#endif // __OBJCOLLIDER_HPP__