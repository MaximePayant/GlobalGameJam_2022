/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Obama.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"
#include "RAY/utils/Input.hpp"

#include "script/GameScene/Obama.hpp"

Obama::Obama(sw::Entity &entity) :
sw::Component(entity),
m_death(false),
m_lastdeath(false),
m_time(sw::Chrono::Wait),
m_state(STAY)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Obama::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Obama::update);
}

void Obama::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto &sprite = m_entity.createComponent<ray::Sprite>("SpriteManager");

    model.setModel("Prison");
    model.setTexture("PrisonVivant1", 0);
    model.setTexture("PrisonVivant2", 1);
    model.setTexture("PrisonVivant3", 2);
    model.setTextureMetallic("PrisonVivant1Metallic", 0);
    model.setTextureMetallic("PrisonVivant2Metallic", 1);
    model.setTextureMetallic("PrisonVivant3Metallic", 2);
    model.setTextureNormal("PrisonVivant1Normal", 0);
    model.setTextureNormal("PrisonVivant2Normal", 1);
    model.setTextureNormal("PrisonVivant3Normal", 2);
    model.setTextureRoughness("PrisonVivant1Roughness", 0);
    model.setTextureRoughness("PrisonVivant2Roughness", 1);
    model.setTextureRoughness("PrisonVivant3Roughness", 2);
    sprite.setTexture("BlackScreen");
    sprite.setColor(255, 255, 255, 0);
}

void Obama::update()
{
    int value;

    if (ray::Input::GetKeyReleased(ray::KEY_A) && !m_time.isRunning()) {
        m_time.start();
        m_state = FADE_IN;
    }
    if (m_time.getElapsedTime() > 0.01 && m_time.isRunning()) {
        auto &sprite = m_entity.getComponent<ray::Sprite>("SpriteManager");
        if (m_state == FADE_IN) {
            value = (sprite.color().getColor().a + 4 >= 255) ? 255 : sprite.color().getColor().a + 4;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (m_time.getTotalTime() >= 3) {
                m_time.start();
                m_state = FADE_OUT;
                m_death = !m_death;
                changeWorld();
            }
        }
        if (m_state == FADE_OUT) {
            value = (sprite.color().getColor().a - 4 <= 0) ? 0 : sprite.color().getColor().a - 4;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (sprite.color().getColor().a == 0)
                m_time.stop();
        }
        m_time.tour();
    }
}

std::string Obama::type() const
{
    return ("Obama");
}

void Obama::changeWorld()
{
    std::string arg = (m_death ? "Mort" : "Vivant");
    auto &model = m_entity.getComponent<ray::Mesh>("MeshManager");

    model.setTexture("Prison" + arg + "1", 0);
    model.setTexture("Prison" + arg + "2", 1);
    model.setTexture("Prison" + arg + "3", 2);
    model.setTextureMetallic("Prison" + arg + "1Metallic", 0);
    model.setTextureMetallic("Prison" + arg + "2Metallic", 1);
    model.setTextureMetallic("Prison" + arg + "3Metallic", 2);
    model.setTextureNormal("Prison" + arg + "1Normal", 0);
    model.setTextureNormal("Prison" + arg + "2Normal", 1);
    model.setTextureNormal("Prison" + arg + "3Normal", 2);
    model.setTextureRoughness("Prison" + arg + "1Roughness", 0);
    model.setTextureRoughness("Prison" + arg + "2Roughness", 1);
    model.setTextureRoughness("Prison" + arg + "3Roughness", 2);
}