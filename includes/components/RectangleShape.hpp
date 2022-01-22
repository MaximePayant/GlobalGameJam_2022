/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectangleShape.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECTANGLESHAPE_HPP__
#define __RECTANGLESHAPE_HPP__

#include "SW/Component.hpp"
#include "SW/utils/Vector.hpp"
#include "RAY/utils/Color.hpp"

class RectangleShape
    :   public sw::Component
{

    private:
        Rectangle m_rect;
        ray::RColor m_fillColor;
        ray::RColor m_fillColor2;
        ray::RColor m_outlineColor;
        float m_roundness;
        float m_outlineThickness;

    public:
        enum Gradient { None, Vertical, Horizontal } gradient;

        RectangleShape(sw::Entity& entity, const sw::Vector2f& size);
        RectangleShape(sw::Entity& entity, const sw::Vector2f& pos, const sw::Vector2f& size);
        ~RectangleShape() override = default;

        void setPosition(const sw::Vector2f& pos);
        sw::Vector2f getPosition() const;
        void setSize(const sw::Vector2f& size);
        sw::Vector2f getSize() const;

        void setFillColor(const ray::RColor& color);
        ray::RColor getFillColor() const;
        void setGradientColor(const ray::RColor& color);
        ray::RColor getGradientColor() const;

        void setOutlineColor(const ray::RColor& color);
        ray::RColor getOutlineColor() const;

        void setOutlineThickness(float thickness);
        float getOutlineThickness() const;

        void setRoundness(float roundness);
        float getRoundness() const;

        void draw() const;

        std::string type() const override { return ("RectangleShape"); }

};

#endif // __RECTANGLESHAPE_HPP__