/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BreashWall.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/BreashWall.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

BreashWall::BreashWall(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &BreashWall::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &BreashWall::update);
}

void BreashWall::start()
{
    m_entity.createComponent<ray::Mesh>("MeshManager").setActive(false);
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, -2}, Vector3{100, 100, 1}).setActive(false);

    // model.setModel("BreashWall");
    // model.setTexture("BreachWallBase", 0);
}

void BreashWall::update()
{}