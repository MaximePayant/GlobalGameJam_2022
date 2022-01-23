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
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("Poster");
    model.setTexture("PrisonVivant1", 0);
}

void Poster::update()
{}