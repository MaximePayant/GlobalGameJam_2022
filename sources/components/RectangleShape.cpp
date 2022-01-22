/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectangleShape.cpp
 *
 * Description:
 * [Change]
 */

#include "RectangleShape.hpp"

#include "SW/utils/Reference.hpp"

#include "RAY/components/Transform.hpp"

RectangleShape::RectangleShape(sw::Entity& entity, const sw::Vector2f& size)
    :   sw::Component{entity},
        m_rect{0, 0, size.x, size.y},
        m_fillColor{ray::White},
        m_fillColor2{ray::White},
        m_outlineColor{ray::White},
        m_roundness{0},
        m_outlineThickness{0}
{

}

RectangleShape::RectangleShape(sw::Entity& entity, const sw::Vector2f& pos, const sw::Vector2f& size)
    :   sw::Component{entity},
        m_rect{pos.x, pos.y, size.x, size.y},
        m_fillColor{ray::White},
        m_fillColor2{ray::White},
        m_outlineColor{ray::White},
        m_roundness{0},
        m_outlineThickness{0}
{

}

void RectangleShape::setPosition(const sw::Vector2f& pos)
{
    m_rect.x = pos.x;
    m_rect.y = pos.y;
}

sw::Vector2f RectangleShape::getPosition() const
{
    return (sw::Vector2f{m_rect.x, m_rect.y});
}

void RectangleShape::setSize(const sw::Vector2f& size)
{
    m_rect.width = size.x;
    m_rect.height = size.y;
}

sw::Vector2f RectangleShape::getSize() const
{
    return (sw::Vector2f{m_rect.width, m_rect.height});
}

void RectangleShape::setFillColor(const ray::RColor& color)
{
    m_fillColor = color;
}

ray::RColor RectangleShape::getFillColor() const
{
    return (m_fillColor);
}

void RectangleShape::setGradientColor(const ray::RColor& color)
{
    m_fillColor2 = color;
}

ray::RColor RectangleShape::getGradientColor() const
{
    return (m_fillColor2);
}

void RectangleShape::setOutlineColor(const ray::RColor& color)
{
    m_outlineColor = color;
}

ray::RColor RectangleShape::getOutlineColor() const
{
    return (m_outlineColor);
}

void RectangleShape::setOutlineThickness(float thickness)
{
    m_outlineThickness = thickness;
}

float RectangleShape::getOutlineThickness() const
{
    return (m_outlineThickness);
}

void RectangleShape::setRoundness(float roundness)
{
    m_roundness = roundness;
}

float RectangleShape::getRoundness() const
{
    return (m_roundness);
}

void RectangleShape::draw()
{
    static sw::Reference<ray::Transform> tfm;

    if (!tfm.hasValue() && m_entity.hasComponent("TransformManager"))
        tfm.emplace(m_entity.getComponent<ray::Transform>("TransformManager"));

    ray::Vector3f tpos = (tfm.hasValue() ? (*tfm).getPosition(): ray::Vector3f{0, 0, 0});
    ray::Vector3f tscale = (tfm.hasValue() ? (*tfm).getPosition(): ray::Vector3f{1, 1, 1});

    sw::Vector2f pos = {m_rect.x + tpos.x, m_rect.y + tpos.y};
    sw::Vector2f size = {m_rect.width * tscale.x, m_rect.height * tscale.y};

    if (m_roundness) {
        DrawRectangleRounded({pos.x, pos.y, size.x, size.y}, m_roundness, 0, m_fillColor.getColor());
        if (m_outlineThickness)
            DrawRectangleRoundedLines({pos.x, pos.y, size.x, size.y}, m_roundness, 0, m_outlineThickness, m_fillColor.getColor());
            return;
    }

    if (gradient == Vertical)
        DrawRectangleGradientV(pos.x, pos.y, size.x, size.y, m_fillColor.getColor(), m_fillColor2.getColor());
    else if (gradient == Horizontal)
        DrawRectangleGradientH(pos.x, pos.y, size.x, size.y, m_fillColor.getColor(), m_fillColor2.getColor());
    else
        DrawRectangle(pos.x, pos.y, size.x, size.y, m_fillColor.getColor());

    if (m_outlineThickness)
        DrawRectangleLines(pos.x, pos.y, size.x, size.y, m_fillColor.getColor());
}
