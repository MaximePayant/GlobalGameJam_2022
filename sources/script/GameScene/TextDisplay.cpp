/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TextDisplay.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "scenes/GameScene.hpp"
#include "script/GameScene/TextDisplay.hpp"

TextDisplay::TextDisplay(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &TextDisplay::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &TextDisplay::update);
}

void TextDisplay::start()
{
    auto &text = m_entity.createComponent<ray::Text>("TextManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");

    text.setString(dynamic_cast<GameScene&>(m_entity.scene()).m_dialogue["Intro-Player"]);
    text.setSpacing(5.0f);
    text.setColor(WHITE);
    text.setFont("ChunkFive");
    text.setSize(30);
    transform.setPosition(150, 900);
}

void TextDisplay::update()
{
}

std::string TextDisplay::type() const
{
    return ("TextDisplay");
}