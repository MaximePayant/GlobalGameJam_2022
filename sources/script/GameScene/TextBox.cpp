/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TextBox.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/TextBox.hpp"
#include "EventInfo/ShowText.hpp"

TextBox::TextBox(sw::Entity &entity) :
sw::Component(entity),
m_state(STAY)
{
    m_entity.scene().eventManager()["Update"].subscribe(this, &TextBox::update);
    m_entity.scene().eventManager()["ShowText"].subscribe(this, &TextBox::showText);
    m_entity.scene().eventManager()["HideText"].subscribe(this, &TextBox::hideText);
}

void TextBox::start()
{
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto &sprite = m_entity.createComponent<ray::Sprite>("SpriteManager");

    transform.setPosition(-60, 700);
    transform.setScale(0.95, 0.95, 0.95);
    sprite.setTexture("DialogueBox");
    sprite.setActive(false);
}

void TextBox::update()
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

std::string TextBox::type() const
{
    return ("TextBox");
}

void TextBox::showText(sw::EventInfo &info)
{
    auto& box = m_entity.getComponent<ray::Sprite>("SpriteManager");

    box.setActive(true);
}

void TextBox::hideText()
{
    auto& box = m_entity.getComponent<ray::Sprite>("SpriteManager");

    box.setActive(false);
}