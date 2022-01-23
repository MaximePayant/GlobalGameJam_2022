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
#include "script/GameScene/TextBox.hpp"
#include "EventInfo/ShowText.hpp"

TextDisplay::TextDisplay(sw::Entity &entity) :
sw::Component(entity),
m_state(STAY)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &TextDisplay::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &TextDisplay::update);
    m_entity.scene().eventManager()["ShowText"].subscribe(this, &TextDisplay::showText);
    m_entity.scene().eventManager()["HideText"].subscribe(this, &TextDisplay::hideText);
}

void TextDisplay::start()
{
    auto &text = m_entity.createComponent<ray::Text>("TextManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto& box = m_entity.scene().createEntity("TextBox");
    static ShowText showText("Intro-Player");
    static sw::EventInfo info(showText);

    text.setString("");
    text.setSpacing(5.0f);
    text.setColor(WHITE);
    text.setFont("ChunkFive");
    text.setSize(30);
    transform.setPosition(150, 900);
    box.createComponent<TextBox>("ScriptManager").start();
    m_entity.scene().eventManager().drop("ShowText", info);
}

void TextDisplay::update()
{
    if (m_state == SHOW && m_time.getElapsedTime() > 0.03) {
        auto& text = m_entity.getComponent<ray::Text>("TextManager");

        text.setNbrDisplayedChar(m_nbr);
        m_nbr++;
        m_time.tour();
        if (text.getNbrDisplayedChar() == text.getString().size()) {
            m_state = STAY;
            m_time.stop();
        }
    }
}

std::string TextDisplay::type() const
{
    return ("TextDisplay");
}

void TextDisplay::showText(sw::EventInfo &info)
{
    auto& infoType = info.getInfo<ShowText>();
    sw::ConcreteComponent auto& text = m_entity.getComponent<ray::Text>("TextManager");
    text.setString(dynamic_cast<GameScene&>(m_entity.scene()).m_dialogue[infoType.m_key]);
    text.setNbrDisplayedChar(0);
    m_state = SHOW;
    m_nbr = 1;
    m_time.start();
}

void TextDisplay::hideText()
{
    sw::ConcreteComponent auto& text = m_entity.getComponent<ray::Text>("TextManager");
    text.setNbrDisplayedChar(0);
    m_state = STAY;
}