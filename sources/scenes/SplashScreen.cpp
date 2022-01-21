/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SplashScreen.cpp
** Description: [CHANGE]
*/

#include "scenes/SplashScreen.hpp"
#include "RAY/components/components.hpp"
#include "RAY/components_manager/managers.hpp"
#include "script/SplashScreen/Logo.hpp"

void SplashScreen::onLoad()
{
    createManager<ray::TransformManager>("TransformManager");
    createManager<ray::SpriteManager>("SpriteManager");
    auto& scriptFact = createManager<sw::AScriptFact>("ScriptManager");
    createManager<ray::AudioManager>("AudioManager");
    eventManager().create("Start");
    eventManager().create("Update");
    auto& logo = createEntity("Logo");

    setLayer("ScriptManager", 0);
    setLayer("AudioManager", 1);
    setLayer("TransformManager", 2);
    setLayer("SpriteManager", 3);

    logo.createComponent<Logo>("ScriptManager");
    eventManager().drop("Start");
}

void SplashScreen::onUpdate()
{
    for (auto& [_, managerName] : m_managerLayer) {
        auto& sys = m_managerMap[managerName];
        if (!sys->isActive())
            continue;
        //sys->neededAction();
        sys->update();
    }
}

void SplashScreen::onUnload()
{

}

std::string SplashScreen::type() const
{
    return ("SplashScreen");
}