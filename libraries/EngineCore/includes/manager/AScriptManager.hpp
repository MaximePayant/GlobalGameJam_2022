/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AScriptManager.hpp
 *
 * Description:
 * Basic Component Manager for all Scripted Component.
 * Use it as template to your own Component Manager.
 */

#ifndef __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__
#define __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__

#include "AManager.hpp"

#include "../component/Component.hpp"

namespace sw
{

    class AScriptManager
        :   public AManager<Component>
    {

        public:
            using AManager<Component>::AManager;
            virtual ~AScriptManager() override = default;

    }; // class AScriptManager

} // namespace sw

#endif // __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__