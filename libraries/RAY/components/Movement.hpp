/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Movement.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MOVEMENT_HPP__
#define __RAYLIB_MODULE_MOVEMENT_HPP__

#include "SW/Component.hpp"
#include "../utils/Vector3.hpp"

namespace ray
{

    class Movement : public sw::Component
    {

        public:
            Movement(sw::Entity& entity);
            Movement(sw::Entity& entity, float xVal, float yVal, float zVal);
            ~Movement() = default;

            float x;
            float y;
            float z;
            Movement& setVector(ray::Vector3f vector);
            [[nodiscard]] std::string type() const override;
    }; // class Movement

} // namespace ray

#endif // __RAYLIB_MODULE_MOVEMENT_HPP__