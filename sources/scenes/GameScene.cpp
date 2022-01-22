/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: GameScene.cpp
** Description: [CHANGE]
*/

#include "scenes/GameScene.hpp"
#include "RAY/components/components.hpp"
#include "RAY/components_manager/managers.hpp"
#include "script/GameScene/Obama.hpp"
#include "script/GameScene/MainMusic.hpp"

void GameScene::onLoad()
{
    createManager<ray::TransformManager>("TransformManager");
    createManager<ray::MeshManager>("MeshManager");
    auto& scriptFact = createManager<sw::AScriptFact>("ScriptManager");
    createManager<ray::CameraManager>("CameraManager");
    createManager<ray::MusicManager>("MusicManager");

    eventManager().create("Start");
    eventManager().create("Update");
    auto& obama = createEntity("Obama");
    auto& camera = createEntity("MainCamera");
    auto& music = createEntity("MusicManager");

    music.createComponent<MainMusic>("MusicManager");
    obama.createComponent<Obama>("ScriptManager");
    camera.createComponent<ray::RCamera>("CameraManager");

    eventManager().drop("Start");
}

void GameScene::onUpdate()
{
    for (auto& [_, managerName] : m_managerLayer) {
        auto& sys = m_managerMap[managerName];
        if (!sys->isActive())
            continue;
        //sys->neededAction();
        sys->update();
    }
}

void GameScene::onUnload()
{

}

std::string GameScene::type() const
{
    return ("GameScene");
}