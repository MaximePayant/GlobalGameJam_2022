/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectMCManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECTMCMANAGER_HPP__
#define __RECTMCMANAGER_HPP__

#include "SW/Manager.hpp"
#include "RectMouseCollider.hpp"

class RectMCManager
    :   public sw::AManager<RectMouseCollider>
{

    public:
        bool isDebuging;

        RectMCManager(const std::string& managerName, sw::AScene& scene, bool IsDebuging = false)
            :   sw::AManager<RectMouseCollider>{managerName, scene},
                isDebuging{IsDebuging}
        {}
        ~RectMCManager() = default;

        void onUpdate() override;

        std::string type() const override { return ("RectMCManager"); }

};

#endif // __RECTMCMANAGER_HPP__