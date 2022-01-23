/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AlarmClock.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/AlarmClock.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

AlarmClock::AlarmClock(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &AlarmClock::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &AlarmClock::update);
}

void AlarmClock::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{1255, 605, -10}, Vector3{50, 50, 1}).setActive(false);

    model.setModel("AlarmClock");
    model.setTexture("AlarmClockBase", 0);
    model.setActive(false);
    transform.setPosition({-1.1, 0, 9.2});
}

void AlarmClock::update()
{}

void AlarmClock::interact()
{
    m_entity.scene().eventManager().drop("ChangeWorld");
}