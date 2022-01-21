/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Texture.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_TEXTURE__
#define __RAYLIB_MODULE_TEXTURE__

#include "RAYLIB/raylib.h"
#include "../RayLibModule_Config.hpp"
#include "SW/Resources.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RTexture : public sw::ITexture
    {
        private:
            Texture2D m_texture;

        public:
            explicit RTexture(Texture2D texture);
            ~RTexture() noexcept override;

            Texture2D operator*() const;
    }; // class RTexture
} // namespace ray

#endif //__RAYLIB_MODULE_TEXTURE__
