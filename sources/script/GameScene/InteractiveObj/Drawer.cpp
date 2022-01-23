/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Drawer.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Drawer.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Drawer::Drawer(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Drawer::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Drawer::update);
}

void Drawer::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("Drawer");
    model.setTexture("DrawerBase", 0);
}

void Drawer::update()
{}