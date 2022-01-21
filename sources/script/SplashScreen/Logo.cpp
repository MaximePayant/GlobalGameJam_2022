/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Logo.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"

#include "RAY/components/components.hpp"
#include "RAY/RayLibModule.hpp"

#include "script/SplashScreen/Logo.hpp"

Logo::Logo(sw::Entity &entity) :
        sw::Component(entity),
        m_state(FADE_IN)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Logo::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Logo::update);
}

void Logo::start()
{
    auto &sprite = m_entity.createComponent<ray::Sprite>("SpriteManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto &audio = m_entity.createComponent<ray::Audio>("AudioManager");

    sprite.setTexture("Logo").setColor({255, 255, 255, 0});
    transform.setPosition(700, 200);
    m_state = FADE_IN;
    audio.addSound("Horn", "Horn").play("Horn");
}

void Logo::update() {
    static sw::Chrono chrono(sw::Chrono::Lauch);
    auto &sprite = m_entity.getComponent<ray::Sprite>("SpriteManager");
    int value;

    if (chrono.getElapsedTime() > 0.01) {
        if (m_state == FADE_IN) {
            value = (sprite.color().getColor().a + 2 >= 255) ? 255 : sprite.color().getColor().a + 2;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (chrono.getTotalTime() >= 3) {
                chrono.start();
                m_state = STAY;
            }
        }
        if (m_state == STAY && chrono.getTotalTime() >= 2) {
            chrono.start();
            m_state = FADE_OUT;
        }
        if (m_state == FADE_OUT) {
            value = (sprite.color().getColor().a - 2 <= 0) ? 0 : sprite.color().getColor().a - 2;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (sprite.color().getColor().a == 0) {
                chrono.stop();
                sw::Engine::getModule<ray::RayLibModule>().SetBackGroundColor(BLACK).ClearWindowType(FLAG_WINDOW_UNDECORATED);
                sw::Engine::setActiveScene("GameScene");
            }
        }
        chrono.tour();
    }
}

std::string Logo::type() const
{
    return ("Logo");
}
