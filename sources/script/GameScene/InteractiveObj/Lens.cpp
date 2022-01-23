/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Lens.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Lens.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Lens::Lens(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Lens::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Lens::update);
}

void Lens::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto& mc = m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{590, 530, -2}, Vector3{50, 50, 100});

    mc.setActive(true);
    model.setModel("Lens");
    model.setTexture("LensBase", 0);
    transform.setPosition({1.2, 0, 1.1});
}

void Lens::update()
{}

void Lens::take()
{
    auto &model = m_entity.getComponent<ray::Mesh>("MeshManager");
    if (m_state == InteractiveObj::Placed)
        model.setColor(Color{255, 255, 255, 0});
    if (m_state == InteractiveObj::Taked)
        model.setColor(Color{0, 0, 0, 255});
}