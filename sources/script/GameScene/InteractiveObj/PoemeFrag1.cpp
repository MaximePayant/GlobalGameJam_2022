/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * PoemeFrag1.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/PoemeFrag1.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

PoemeFrag1::PoemeFrag1(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &PoemeFrag1::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &PoemeFrag1::update);
}

void PoemeFrag1::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, -2}, Vector3{100, 100, 1}).setActive(false);

    model.setModel("PoemeFrag1");
    model.setTexture("Note1Base", 0);
}

void PoemeFrag1::update()
{}