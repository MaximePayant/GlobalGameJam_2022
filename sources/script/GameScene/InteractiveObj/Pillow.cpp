/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Pillow.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Pillow.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Pillow::Pillow(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Pillow::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Pillow::update);
}

void Pillow::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{880, 290, 0}, Vector3{140, 120, 1});

    model.setModel("Pillow");
    model.setTexture("PrisonVivant1", 0);
}

void Pillow::update()
{}

void Pillow::interact()
{
    m_entity.getComponent<ray::Transform>("TransformManager").setPosition({0, 0, 1});
    m_entity.getComponent<ObjCollider>("ObjColliderManager").setActive(false);
    m_entity.getComponent<ray::Mesh>("MeshManager").setColor(Color{255, 255, 255, 255});

    auto& ac = m_entity.scene().getEntity("ObjBall");
    ac.getComponent<ray::Mesh>("MeshManager").setActive(true);
    ac.getComponent<ObjCollider>("ObjColliderManager").setActive(true);
}