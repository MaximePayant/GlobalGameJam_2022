/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectMCManager.cpp
 *
 * Description:
 * [Change]
 */

#include "RectMCManager.hpp"

#include "SW/Engine.hpp"
#include "RAY/RayLibModule.hpp"

void RectMCManager::onUpdate()
{
    for (auto& [_, name] : m_componentLayer) {
        auto& rshape = m_components[name];

        if (!rshape->isActive())
            continue;

        auto mpos = ray::Input::GetMousePosition();
        if (rshape->checkCollision(sw::Vector2i{mpos.x, mpos.y})) {
            if (rshape->state() == RectMouseCollider::None) {
                rshape->onHover();
                rshape->state(RectMouseCollider::Hover);
                rshape->startClock();
            }

            // if (rshape->clock() > 0.5 && rshape->state() != RectMouseCollider::Hover) {
            //     if (rshape->state() == RectMouseCollider::Lclick)
            //         rshape->onLeftRelease();
            //     if (rshape->state() == RectMouseCollider::Rclick)
            //         rshape->onRightRelease();
            //     rshape->state(RectMouseCollider::Hover);
            // }
        }
        else if (rshape->state() != RectMouseCollider::None) {
            rshape->onNormal();
            rshape->state(RectMouseCollider::None);
        }

        if (isDebuging) {
            rshape->shape().draw();
        }
    }
}