/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: ColliderManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_COLLIDER_MANAGER_HPP__
#define __RAYLIB_MODULE_COLLIDER_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Collider.hpp"
#include "../RayLibModule_Config.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT ColliderManager : public sw::AManager<Collider>
    {
        public:
            using sw::AManager<Collider>::AManager;
            ~ColliderManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;

    }; // class ColliderManager

} // namespace ray

#endif // __RAYLIB_MODULE_COLLIDER_MANAGER_HPP__