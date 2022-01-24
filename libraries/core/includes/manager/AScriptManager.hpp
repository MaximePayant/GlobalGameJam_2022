/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ScriptFact.hpp
*/

#ifndef __SHIPWRECK_SCRIPTFACT_HPP__
#define __SHIPWRECK_SCRIPTFACT_HPP__

#include "AManager.hpp"

#include "../component/Component.hpp"

namespace sw
{

    class AScriptFact
        :   public AManager<Component>
    {
        public:
            using AManager<Component>::AManager;
            ~AScriptFact() override = default;
            void onUpdate() override { m_scene.eventManager().drop("Update"); };
            [[nodiscard]] std::string type() const override { return ("ScriptManager"); }
    };

}

#endif // __SHIPWRECK_SCRIPTFACT_HPP__