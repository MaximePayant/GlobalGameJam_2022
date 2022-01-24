/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Pen.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Pen.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Pen::Pen(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Pen::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Pen::update);
}

void Pen::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 1}).setActive(false);

    model.setModel("Pen");
    model.setTexture("PenBase", 0);
}

void Pen::update()
{}