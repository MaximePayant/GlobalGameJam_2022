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
#include "RAY/components/Mesh.hpp"
#include "InteractiveObj/InteractiveObj.hpp"

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
        void rightClickPressed_Event(sw::EventInfo& info);
        void leftClickReleased_Event();
        void rightClickReleased_Event();

        void onEnterCollide() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(ray::Lime.getColor());
        };
        void onQuitCollide() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(Color{0, 0, 0, 255});
        };

        void onLeftClick() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(ray::Red.getColor());
        };
        void onLeftRelease() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(ray::Lime.getColor());
            m_entity.getComponent<InteractiveObj>("ScriptManager").interact();
        };

        void onRightClick() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(ray::Red.getColor());
        };
        void onRightRelease() {
            m_entity.getComponent<ray::Mesh>("MeshManager").setColor(ray::Lime.getColor());
            m_entity.getComponent<InteractiveObj>("ScriptManager").take();
        };

};

#endif // __OBJCOLLIDER_HPP__