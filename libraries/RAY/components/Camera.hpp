/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Camera.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_CAMERA_HPP__
#define __RAYLIB_MODULE_CAMERA_HPP__

#include "SW/Component.hpp"
#include "RAYLIB/raylib.h"
#include "../utils/Vector3.hpp"

namespace ray
{
    class RCamera :
        public sw::Component
    {
        private:
            Camera m_camera;
            int m_projection;
            float m_fov;
            ray::Vector3<float> m_up;
            ray::Vector3<float> m_target;

        public:
            RCamera() = delete;
            ~RCamera() = default;
            explicit RCamera(sw::Entity &entityRef);

            RCamera& setProjection(int projection);
            RCamera& setFOV(float fov);
            RCamera& setUp(float x, float y, float z);
            RCamera& setUp(const ray::Vector3<float>& vector);
            RCamera& setTarget(float x, float y, float z);
            RCamera& setTarget(const ray::Vector3<float>& vector);
            RCamera& setPosition(ray::Vector3f vector);
            RCamera& setPosition(float x, float y, float z);

            [[nodiscard]]int getProjection() const;
            [[nodiscard]]float getFOV() const;
            [[nodiscard]]ray::Vector3<float> getUp() const;
            [[nodiscard]]ray::Vector3<float> getTarget() const;
            [[nodiscard]]Camera *getCamera();
            [[nodiscard]] std::string type() const override;
    };
}

#endif //__RAYLIB_MODULE_CAMERA_HPP__
