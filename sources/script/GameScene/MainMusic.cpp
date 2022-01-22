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
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &MainMusic::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &MainMusic::update);
}

void MainMusic::start()
{
    auto &music = m_entity.createComponent<ray::MusicStream>("MusicManager");

    music.addSound("Bass Suspens", "Bass Suspens");
    music.play("Bass Suspens");
}

void MainMusic::update()
{
}

std::string MainMusic::type() const
{
    return ("MainMusic");
}