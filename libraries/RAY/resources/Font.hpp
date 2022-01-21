/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Font.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_FONT__
#define __RAYLIB_MODULE_FONT__

#include "RAYLIB/raylib.h"
#include "../RayLibModule_Config.hpp"
#include "SW/Resources.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RFont : public sw::IFont
    {
        private:
            Font m_font;

        public:
            explicit RFont(Font font);
            ~RFont() noexcept override;

            Font operator*() const;
    }; // class RFront
} // namespace ray

#endif //__RAYLIB_MODULE_FONT__
