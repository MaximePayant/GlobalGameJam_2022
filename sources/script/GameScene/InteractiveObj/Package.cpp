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
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{1240, 590, 0}, Vector3{90, 90, 1});

    model.setModel("Package");
    model.setTexture("PackBase", 0);
}

void Package::update()
{}

void Package::interact()
{
    m_entity.getComponent<ray::Mesh>("MeshManager").setActive(false);

    auto& ac = m_entity.scene().getEntity("ObjAlarmClock");
    ac.getComponent<ray::Mesh>("MeshManager").setActive(true);
    ac.getComponent<ObjCollider>("ObjColliderManager").setActive(true);
}