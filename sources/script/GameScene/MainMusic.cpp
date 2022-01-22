/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MainMusic.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/MainMusic.hpp"

MainMusic::MainMusic(sw::Entity &entity) :
sw::Component(entity),
m_time(sw::Chrono::Wait),
m_nextPonct((std::rand() % 30))
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &MainMusic::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &MainMusic::update);
}

void MainMusic::start()
{
    auto &music = m_entity.createComponent<ray::MusicStream>("MusicManager");
    auto &audio = m_entity.createComponent<ray::Audio>("AudioManager");

    music.addSound("Bass Suspens", "Bass Suspens");
    music.play("Bass Suspens");
    audio.addSound("Ponctuation 1", "0");
    audio.addSound("Ponctuation 2", "1");
    audio.addSound("Ponctuation 3", "2");
    m_time.start();
}

void MainMusic::update()
{
    if (m_time.getElapsedTime() > m_nextPonct) {
        m_entity.getComponent<ray::Audio>("AudioManager").play(std::to_string(std::rand() % 3));
        m_time.tour();
        m_nextPonct = (std::rand() % 30);
    }
}

std::string MainMusic::type() const
{
    return ("MainMusic");
}