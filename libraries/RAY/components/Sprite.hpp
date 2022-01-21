/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_SPRITE_HPP__
#define __RAYLIB_MODULE_SPRITE_HPP__

#include "SW/Component.hpp"
#include "SW/Utils.hpp"
#include "../RayLibModule_Config.hpp"
#include "../resources/Texture.hpp"
#include "../utils/Color.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT Sprite : public sw::Component
    {
        private:
            std::shared_ptr<ray::RTexture> m_texture;
            ray::RColor m_color;
            Image m_image;
            Rectangle m_rectangle;
            bool m_invertedX;
            bool m_invertedY;

        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            explicit Sprite(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default destructor
            ////////////////////////////////////////////////////////////////////////////
            ~Sprite() = default;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get the current texture associated with the sprite
            ///
            /// \return reference to the texture
            ////////////////////////////////////////////////////////////////////////////
            [[nodiscard]] const ray::RTexture& texture() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the displayed texture
            ///
            /// \param texture
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setTexture(std::string name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a rect displayed
            ///
            /// \param rect
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setTextureRect(Rectangle rect);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a color (this color is multiplied with the texture)
            ///
            /// \param color
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setColor(const Color &color);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a color (this color is multiplied with the texture)
            ///
            /// \param color
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setColor(int r, int g, int b, int a);

            void loadSpriteImage();
            bool PointOnImage(const sw::Vector2f& point);

            [[nodiscard]] ray::RColor color() const;

            void invertX(bool invert);
            void invertY(bool invert);

            [[nodiscard]] bool isInvertX() const;
            [[nodiscard]] bool isInvertY() const;

            [[nodiscard]] Rectangle getRect() const;

            [[nodiscard]] std::string type() const override;

            Sprite update();

    }; // class Sprite

} // namespace ray

#endif //__RAYLIB_MODULE_SPRITE_HPP__
