/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Text.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_TEXT_HPP__
#define __RAYLIB_MODULE_TEXT_HPP__

#include "SW/Component.hpp"
#include "../resources/Font.hpp"
#include "../utils/Color.hpp"

namespace ray
{
    class Text : public sw::Component
    {
        private:
            std::string m_text;
            float m_size;
            std::shared_ptr<ray::RFont> m_font;
            float m_spacing;
            RColor m_color;
            unsigned int m_nbrDisplayedChar;

        public:
            Text(sw::Entity& entity);
            ~Text() = default;
            Text& setString(std::string message);
            Text& setSize(float size);
            Text& setFont(std::string fontName);
            Text& setSpacing(float spacing);
            Text& setColor(Color color);
            Text& setColor(int r, int g, int b, int a);
            Text& setNbrDisplayedChar(unsigned int nbr);

            [[nodiscard]] std::string getString() const;
            [[nodiscard]] float getSize() const;
            [[nodiscard]] ray::RFont& getFont() const;
            [[nodiscard]] float getSpacing() const;
            [[nodiscard]] RColor getColor() const;
            [[nodiscard]] unsigned int getNbrDisplayedChar() const;
            [[nodiscard]] std::string type() const override;
    }; // class Text
} // namespace ray

#endif //__RAYLIB_MODULE_TEXT_HPP__
