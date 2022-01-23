/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Hook.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Hook.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Hook::Hook(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Hook::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Hook::update);
}

void Hook::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, -2}, Vector3{100, 100, 1}).setActive(false);

    model.setModel("Hook");
    model.setTexture("HookBase", 0);
}

void Hook::update()
{}