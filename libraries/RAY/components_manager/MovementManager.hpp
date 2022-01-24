/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MovementManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MOVEMENT_MANAGER_HPP__
#define __RAYLIB_MODULE_MOVEMENT_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Movement.hpp"
#include "../RayLibModule_Config.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT MovementManager : public sw::AManager<Movement>
    {
        public:
            using sw::AManager<Movement>::AManager;
            ~MovementManager() = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;
    }; // class MovementManager

} // namespace ray

#endif //__RAYLIB_MODULE_MOVEMENT_MANAGER_HPP__
