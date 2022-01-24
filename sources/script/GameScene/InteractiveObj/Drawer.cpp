/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Drawer.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/Drawer.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

Drawer::Drawer(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Drawer::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Drawer::update);
    m_state = InteractiveObj::State::Closed;
}

void Drawer::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{590, 500, 0}, Vector3{20, 100, 1});

    model.setModel("Drawer");
    model.setTexture("DrawerBase", 0);
}

void Drawer::update()
{}

void Drawer::interact()
{
    if (m_state == InteractiveObj::State::Opened) {
        auto &transform = m_entity.getComponent<ray::Transform>("TransformManager");
        transform.setPosition({0, 0, 0});
        auto& oc = m_entity.getComponent<ObjCollider>("ObjColliderManager");
        oc.setOrigin(Vector3{590, 500, 0});
        oc.setSize(Vector3{20, 100, 1});

        auto& ac = m_entity.scene().getEntity("ObjLens");
        ac.getComponent<ray::Mesh>("MeshManager").setActive(false);
        ac.getComponent<ObjCollider>("ObjColliderManager").setActive(false);

        m_state = InteractiveObj::State::Closed;
    }
    else if (m_state == InteractiveObj::State::Closed) {
        auto &transform = m_entity.getComponent<ray::Transform>("TransformManager");
        transform.setPosition({0, 0, 0.8});
        auto& oc = m_entity.getComponent<ObjCollider>("ObjColliderManager");
        oc.setOrigin(Vector3{590, 500, -2});
        oc.setSize(Vector3{90, 100, 1});

        auto& ac = m_entity.scene().getEntity("ObjLens");
        ac.getComponent<ray::Mesh>("MeshManager").setActive(true);
        ac.getComponent<ObjCollider>("ObjColliderManager").setActive(true);

        m_state = InteractiveObj::State::Opened;
    }
}