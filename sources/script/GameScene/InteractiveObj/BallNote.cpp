/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BallNote.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/BallNote.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

BallNote::BallNote(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &BallNote::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &BallNote::update);
}

void BallNote::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("BallNote");
    model.setTexture("Note1Base", 0);
}

void BallNote::update()
{}