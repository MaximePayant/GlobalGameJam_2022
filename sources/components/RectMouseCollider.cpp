/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** RectMouseCollider.cpp
*/

#include "RAY/components/Transform.hpp"

#include "SW/Entity.hpp"
#include "SW/Event.hpp"

#include "RectMouseCollider.hpp"
#include "EventInfo/MousePosition.hpp"

RectMouseCollider::RectMouseCollider(sw::Entity& entity, const sw::Vector2f& pos, const sw::Vector2f& size)
    :   sw::Component(entity),
        m_state{None},
        m_rect{pos.x, pos.y, size.x, size.y},
        m_clock{},
        m_shape{entity, pos, size}
{
    m_shape.setOutlineColor(ray::Red);
    m_shape.setOutlineThickness(2);

    auto& emanager = entity.scene().eventManager();
    emanager["Mouse_LeftClick_Pressed"].subscribe(this, &RectMouseCollider::leftClickPressed_Event);
    emanager["Mouse_RightClick_Pressed"].subscribe(this, &RectMouseCollider::rightClickPressed_Event);

    emanager["Mouse_LeftClick_Released"].subscribe(this, &RectMouseCollider::leftClickReleased_Event);
    emanager["Mouse_RightClick_Released"].subscribe(this, &RectMouseCollider::rightClickReleased_Event);
}

void RectMouseCollider::leftClickPressed_Event(sw::EventInfo& info)
{
    if (!m_isActive)
        return;

    auto& mpos = info.getInfo<MousePosition_EventInfo>();
    auto vector = sw::Vector2f{mpos.x, mpos.y};
    if (checkCollision(vector)
    && m_state == RectMouseCollider::Hover) {
        onLeftClick();
        m_state = RectMouseCollider::Lclick;
        startClock();
    }
}

void RectMouseCollider::leftClickReleased_Event()
{
    if (!m_isActive || m_state != RectMouseCollider::Lclick)
        return;

    onLeftRelease();
    m_state = RectMouseCollider::Hover;
}

void RectMouseCollider::rightClickPressed_Event(sw::EventInfo& info)
{
    if (!m_isActive)
        return;

    auto& mpos = info.getInfo<MousePosition_EventInfo>();
    auto vector = sw::Vector2f{mpos.x, mpos.y};

    if (checkCollision(vector)
    && m_state == RectMouseCollider::Hover) {
        onRightClick();
        m_state = RectMouseCollider::Rclick;
        startClock();
    }
}

void RectMouseCollider::rightClickReleased_Event()
{
    if (!m_isActive || m_state != RectMouseCollider::Rclick)
        return;

    onRightRelease();
    m_state = RectMouseCollider::Hover;
}

bool RectMouseCollider::checkCollision(sw::Vector2f& point)
{
    static sw::Reference<ray::Transform> tfm;

    if (!tfm.hasValue() && m_entity.hasComponent("TransformManager"))
        tfm.emplace(m_entity.getComponent<ray::Transform>("TransformManager"));

    ray::Vector3f tpos = (tfm.hasValue() ? (*tfm).getPosition(): ray::Vector3f{0, 0, 0});
    ray::Vector3f tscale = (tfm.hasValue() ? (*tfm).getPosition(): ray::Vector3f{1, 1, 1});

    sw::Vector2f pos = {m_rect.x + tpos.x, m_rect.y + tpos.y};
    sw::Vector2f size = {m_rect.width * tscale.x, m_rect.height * tscale.y};

    sw::FloatRect rect(pos, size);

    return (rect.contains(point.x, point.y));
}