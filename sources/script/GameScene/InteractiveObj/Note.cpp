/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Note.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Note.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Note::Note(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Note::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Note::update);
}

void Note::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, -2}, Vector3{100, 100, 1}).setActive(false);

    model.setModel("Note");
    model.setTexture("Note1Base", 0);
}

void Note::update()
{}