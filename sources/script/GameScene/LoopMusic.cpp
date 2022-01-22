/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: LoopMusic.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/LoopMusic.hpp"

LoopMusic::LoopMusic(sw::Entity &entity) :
sw::Component(entity),
m_time(sw::Chrono::Wait),
m_nextPonct(120)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &LoopMusic::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &LoopMusic::update);
}

void LoopMusic::start()
{
    auto &music = m_entity.createComponent<ray::Audio>("AudioManager");

    music.addSound("Bass Stress", "Bass Stress");
    m_time.start();
}

void LoopMusic::update()
{
    if (m_nextPonct != -1 && m_time.getElapsedTime() > m_nextPonct) {
        m_entity.getComponent<ray::Audio>("AudioManager").play("Bass Stress");
        m_time.stop();
        m_nextPonct = -1;
    }
}

std::string LoopMusic::type() const
{
    return ("LoopMusic");
}