/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: CameraManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_CAMERA_MANAGER_HPP__
#define __RAYLIB_MODULE_CAMERA_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Camera.hpp"
#include "../RayLibModule_Config.hpp"

namespace ray
{

    class RAY_GRAPH_MODULE_EXPORT CameraManager : public sw::AManager<RCamera>
    {
    public:
        using sw::AManager<RCamera>::AManager;

        void onUpdate() override;
        [[nodiscard]] std::string type() const override;
    }; // class CameraManager

} // namespace ray

#endif //__RAYLIB_MODULE_CAMERA_MANAGER_HPP__
