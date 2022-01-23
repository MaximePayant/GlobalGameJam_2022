/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Package.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Package.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Package::Package(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Package::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Package::update);
}

void Package::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("Package");
    model.setTexture("PackBase", 0);
}

void Package::update()
{}