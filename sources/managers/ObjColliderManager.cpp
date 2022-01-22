/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ObjColliderManager.cpp
 *
 * Description:
 * [Change]
 */

#include "ObjColliderManager.hpp"
#include "RAY/utils/Color.hpp"
#include "RAY/RayLibModule.hpp"
#include "RAY/utils/Input.hpp"
#include "RAY/components_manager/CameraManager.hpp"

void ObjColliderManager::onUpdate()
{
    Camera *camera = m_scene.getManager<ray::CameraManager>("CameraManager")["MainCamera"].getCamera();
    auto mray = GetMouseRay(GetMousePosition(), *camera);

    ray::RayCollider ray(m_scene.getEntity("MainCamera"), Vector3{GetMousePosition().x, GetMousePosition().y, 0}, mray.direction);
    sw::Speech::Debug("MouseRay Pos : " + std::to_string(mray.position.x) + " / " + std::to_string(mray.position.y));
    sw::Speech::Debug("MouseRay Dir : " + std::to_string(mray.direction.x) + " / " + std::to_string(mray.direction.y));
    for (auto& [_, name] : m_componentLayer) {
        auto& rshape = m_components[name];

        if (!rshape->isActive())
            continue;

        if (GetRayCollisionBox(ray.ray(), rshape->cube()).hit) {
            if (rshape->state() == ObjCollider::None) {
                rshape->onEnterCollide();
                rshape->state(ObjCollider::Hover);
            }
        }
        else if (rshape->state() != ObjCollider::None) {
            rshape->onQuitCollide();
            rshape->state(ObjCollider::None);
        }

        if (isDebuging)
            rshape->draw(rshape->color());
    }
}