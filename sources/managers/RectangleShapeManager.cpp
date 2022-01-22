/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectangleShapeManager.cpp
 *
 * Description:
 * [Change]
 */

#include "RectangleShapeManager.hpp"

void RectangleShapeManager::onUpdate()
{
    for (auto& [_, name] : m_componentLayer) {
        auto& rshape = m_components[name];

        if (!rshape->isActive())
            continue;
        rshape->draw();
    }
}