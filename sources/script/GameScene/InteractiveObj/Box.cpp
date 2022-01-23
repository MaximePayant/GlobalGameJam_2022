/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Box.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Box.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Box::Box(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Box::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Box::update);
}

void Box::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("Box");
    model.setTexture("BoxBase", 0);
}

void Box::update()
{}