/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Obama.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/Obama.hpp"

Obama::Obama(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Obama::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Obama::update);
}

void Obama::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");

    model.setModel("Obama");
    model.setTexture("ObamaTexture");
}

void Obama::update()
{
    m_entity.getComponent<ray::Transform>("TransformManager").rotate(1);
}

std::string Obama::type() const
{
    return ("Obama");
}