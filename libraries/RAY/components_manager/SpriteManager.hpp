/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_SPRITE_MANAGER_HPP__
#define __RAYLIB_MODULE_SPRITE_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Sprite.hpp"
#include "../RayLibModule_Config.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT SpriteManager : public sw::AManager<Sprite>
    {
        public:
            using sw::AManager<Sprite>::AManager;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;
    }; // class SpriteManager

} // namespace ray

#endif //__RAYLIB_MODULE_SPRITE_MANAGER_HPP__
