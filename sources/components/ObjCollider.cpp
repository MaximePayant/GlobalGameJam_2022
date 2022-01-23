/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ObjCollider.cpp
 *
 * Description:
 * [Change]
 */

#include "SW/Entity.hpp"
#include "SW/Event.hpp"
#include "ObjCollider.hpp"
#include "EventInfo/MousePosition.hpp"
#include "RAY/components_manager/CameraManager.hpp"
#include "RAY/utils/Color.hpp"

ObjCollider::ObjCollider(sw::Entity& entity)
    :   ray::CubeCollider{entity},
        m_state{None},
        m_color{ray::Green.getColor()}
{
    auto& emanager = entity.scene().eventManager();
    emanager["Mouse_LeftClick_Pressed"].subscribe(this, &ObjCollider::leftClickPressed_Event);
    emanager["Mouse_RightClick_Pressed"].subscribe(this, &ObjCollider::rightClickPressed_Event);
    emanager["Mouse_LeftClick_Released"].subscribe(this, &ObjCollider::leftClickReleased_Event);
    emanager["Mouse_RightClick_Released"].subscribe(this, &ObjCollider::rightClickReleased_Event);
}

ObjCollider::ObjCollider(sw::Entity& entity, const Vector3& size)
    :   ray::CubeCollider{entity, size},
        m_state{None},
        m_color{ray::Green.getColor()}
{
    auto& emanager = entity.scene().eventManager();
    emanager["Mouse_LeftClick_Pressed"].subscribe(this, &ObjCollider::leftClickPressed_Event);
    emanager["Mouse_RightClick_Pressed"].subscribe(this, &ObjCollider::rightClickPressed_Event);
    emanager["Mouse_LeftClick_Released"].subscribe(this, &ObjCollider::leftClickReleased_Event);
    emanager["Mouse_RightClick_Released"].subscribe(this, &ObjCollider::rightClickReleased_Event);
}

ObjCollider::ObjCollider(sw::Entity& entity, const Vector3& origin, const Vector3& size)
    :   ray::CubeCollider{entity, origin, size},
        m_state{None},
        m_color{ray::Green.getColor()}
{
    auto& emanager = entity.scene().eventManager();
    emanager["Mouse_LeftClick_Pressed"].subscribe(this, &ObjCollider::leftClickPressed_Event);
    emanager["Mouse_RightClick_Pressed"].subscribe(this, &ObjCollider::rightClickPressed_Event);
    emanager["Mouse_LeftClick_Released"].subscribe(this, &ObjCollider::leftClickReleased_Event);
    emanager["Mouse_RightClick_Released"].subscribe(this, &ObjCollider::rightClickReleased_Event);
}

void ObjCollider::leftClickPressed_Event(sw::EventInfo& info)
{
    if (!m_isActive)
        return;

    Camera *camera = m_entity.scene().getManager<ray::CameraManager>("CameraManager")["MainCamera"].getCamera();
    auto& mpos = info.getInfo<MousePosition_EventInfo>();
    auto mray = GetMouseRay(Vector2{(float)mpos.x, (float)mpos.y}, *camera);

    ray::RayCollider ray(m_entity.scene().getEntity("MainCamera"), Vector3{GetMousePosition().x, GetMousePosition().y, 0}, mray.direction);

    ray.draw(ray::Green.getColor());
    if (collide(ray)) {
        onLeftClick();
        m_state = State::Click;
    }
}

void ObjCollider::leftClickReleased_Event()
{
    if (!m_isActive || m_state != ObjCollider::Click)
        return;

    onLeftRelease();
    m_state = State::Hover;
}

void ObjCollider::rightClickPressed_Event(sw::EventInfo& info)
{
    if (!m_isActive)
        return;

    Camera *camera = m_entity.scene().getManager<ray::CameraManager>("CameraManager")["MainCamera"].getCamera();
    auto& mpos = info.getInfo<MousePosition_EventInfo>();
    auto mray = GetMouseRay(Vector2{(float)mpos.x, (float)mpos.y}, *camera);

    ray::RayCollider ray(m_entity.scene().getEntity("MainCamera"), Vector3{GetMousePosition().x, GetMousePosition().y, 0}, mray.direction);

    ray.draw(ray::Green.getColor());
    if (collide(ray)) {
        onRightClick();
        m_state = State::Click;
    }
}

void ObjCollider::rightClickReleased_Event()
{
    if (!m_isActive || m_state != ObjCollider::Click)
        return;

    onRightRelease();
    m_state = State::Hover;
}