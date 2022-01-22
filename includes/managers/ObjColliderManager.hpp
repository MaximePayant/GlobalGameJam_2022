/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ObjColliderManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __OBJCOLLIDERMANAGER_HPP__
#define __OBJCOLLIDERMANAGER_HPP__

#include "SW/Manager.hpp"
#include "ObjCollider.hpp"

class ObjColliderManager
    :   public sw::AManager<ObjCollider>
{

    public:
        bool isDebuging;

        ObjColliderManager(const std::string& managerName, sw::AScene& scene, bool IsDebuging = false)
            :   sw::AManager<ObjCollider>{managerName, scene},
                isDebuging{IsDebuging}
        {}
        ~ObjColliderManager() = default;

        void onUpdate() override;

        std::string type() const override { return ("ObjColliderManager"); }

};

#endif // __OBJCOLLIDERMANAGER_HPP__