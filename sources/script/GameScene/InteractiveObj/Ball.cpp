/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Ball.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Ball.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Ball::Ball(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Ball::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Ball::update);
}

void Ball::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, -2}, Vector3{100, 100, 1}).setActive(false);

    model.setModel("Ball");
    model.setTexture("BallBase", 0);
}

void Ball::update()
{}