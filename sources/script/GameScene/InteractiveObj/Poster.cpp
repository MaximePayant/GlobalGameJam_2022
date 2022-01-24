/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Poster.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Poster.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Poster::Poster(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Poster::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Poster::update);
}

void Poster::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{570, 850, 0}, Vector3{200, 100, 1});

    model.setModel("Poster");
    model.setTexture("PrisonVivant1", 0);
}

void Poster::update()
{}

void Poster::interact()
{
    m_entity.getComponent<ray::Mesh>("MeshManager").setActive(false);
    m_entity.getComponent<ObjCollider>("ObjColliderManager").setActive(false);

    auto& ac = m_entity.scene().getEntity("ObjBox");
    ac.getComponent<ray::Mesh>("MeshManager").setActive(true);
    ac.getComponent<ObjCollider>("ObjColliderManager").setActive(true);
}