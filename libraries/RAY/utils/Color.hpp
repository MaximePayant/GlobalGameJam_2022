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
            ~RColor() = default;
            void setColor(int red, int blue, int green, int alpha);
            void setColor(Color color);
            [[nodiscard]] Color getColor() const;
    }; // class RColor

} // namespace ray

#endif //__RAYMODULE_COLOR_HPP__
