/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Color.hpp
** Description: [CHANGE]
*/

#ifndef __RAYMODULE_COLOR_HPP__
#define __RAYMODULE_COLOR_HPP__

#include "RAYLIB/raylib.h"

namespace ray
{
    class RColor
    {
        private:
            Color m_color;
        public:
            RColor();
            RColor(unsigned char red, unsigned char blue, unsigned char green, unsigned char alpha)
                :   m_color{red, blue, green, alpha}
            {}
            ~RColor() = default;
            void setColor(int red, int blue, int green, int alpha);
            void setColor(Color color);
            [[nodiscard]] Color getColor() const;

    }; // class RColor

    static const RColor LightGray  = { 200, 200, 200, 255 };   // Light Gray
    static const RColor Gray       = { 130, 130, 130, 255 };   // Gray
    static const RColor Darkgray   = { 80, 80, 80, 255 };      // Dark Gray
    static const RColor Yellow     = { 253, 249, 0, 255 };     // Yellow
    static const RColor Gold       = { 255, 203, 0, 255 };     // Gold
    static const RColor Orange     = { 255, 161, 0, 255 };     // Orange
    static const RColor Pink       = { 255, 109, 194, 255 };   // Pink
    static const RColor Red        = { 230, 41, 55, 255 };     // Red
    static const RColor Maroon     = { 190, 33, 55, 255 };     // Maroon
    static const RColor Green      = { 0, 228, 48, 255 };      // Green
    static const RColor Lime       = { 0, 158, 47, 255 };      // Lime
    static const RColor DarkGreen  = { 0, 117, 44, 255 };      // Dark Green
    static const RColor SkyBlue    = { 102, 191, 255, 255 };   // Sky Blue
    static const RColor Blue       = { 0, 121, 241, 255 };     // Blue
    static const RColor DarkBlue   = { 0, 82, 172, 255 };      // Dark Blue
    static const RColor Purple     = { 200, 122, 255, 255 };   // Purple
    static const RColor Violet     = { 135, 60, 190, 255 };    // Violet
    static const RColor DarkPurple = { 112, 31, 126, 255 };    // Dark Purple
    static const RColor Beige      = { 211, 176, 131, 255 };   // Beige
    static const RColor Brown      = { 127, 106, 79, 255 };    // Brown
    static const RColor DarkBrown  = { 76, 63, 47, 255 };      // Dark Brown

    static const RColor White      = { 255, 255, 255, 255 };   // White
    static const RColor Black      = { 0, 0, 0, 255 };         // Black
    static const RColor Blank      = { 0, 0, 0, 0 };           // Blank (Transparent)
    static const RColor Magenta    = { 255, 0, 255, 255 };     // Magenta
    static const RColor RayWhite   = { 245, 245, 245, 255 };   // My own White (raylib logo)

} // namespace ray

#endif //__RAYMODULE_COLOR_HPP__
