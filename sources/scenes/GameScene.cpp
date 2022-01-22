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
#include "script/GameScene/LoopMusic.hpp"

#include "RectMouseCollider.hpp"
#include "RectMCManager.hpp"
#include "RectangleShapeManager.hpp"
#include "ButtonTest.hpp"
#include "EventInfo/MousePosition.hpp"

void GameScene::onLoad()
{
    createManager<ray::TransformManager>("TransformManager");
    createManager<ray::MeshManager>("MeshManager");
    auto& scriptFact = createManager<sw::AScriptFact>("ScriptManager");
    createManager<ray::CameraManager>("CameraManager");
    createManager<ray::MusicManager>("MusicManager");
    createManager<ray::AudioManager>("AudioManager");

    m_eventManager.create("Mouse_LeftClick_Pressed");
    m_eventManager.create("Mouse_RightClick_Pressed");
    m_eventManager.create("Mouse_LeftClick_Released");
    m_eventManager.create("Mouse_RightClick_Released");
    eventManager().create("Start");
    eventManager().create("Update");
    auto& obama = createEntity("Obama");
    auto& camera = createEntity("MainCamera");
    auto& music = createEntity("MusicManager");
    auto& loop = createEntity("MusicLoop");

    music.createComponent<MainMusic>("ScriptManager");
    loop.createComponent<LoopMusic>("ScriptManager");
    obama.createComponent<Obama>("ScriptManager");
    camera.createComponent<ray::RCamera>("CameraManager");

    createManager<RectMCManager>("RectMCManager").isDebuging = true;
    auto& mc = createEntity("MouseCollider");
    mc.createComponent<Button>("RectMCManager", sw::Vector2f{0, 0}, sw::Vector2f{100, 50});

    eventManager().drop("Start");
}

static void updateMousePosition(MousePosition_EventInfo& info)
{
    auto mpos = ray::Input::GetMousePosition();

    info.x = mpos.x;
    info.y = mpos.y;
}

void GameScene::event()
{
    static MousePosition_EventInfo mpos{0, 0};
    static sw::EventInfo info{mpos};

    updateMousePosition(mpos);
    if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT)) {
        sw::Speech::Debug("LEFT CLICK !!!!!");
        m_eventManager.drop("Mouse_LeftClick_Pressed", info);
    }
    else if (ray::Input::IsMouseButtonReleased(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_eventManager.drop("Mouse_LeftClick_Released");

    if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_RIGHT)) {
        sw::Speech::Debug("RIGHT CLICK !!!!!");
        m_eventManager.drop("Mouse_RightClick_Pressed", info);
    }
    else if (ray::Input::IsMouseButtonReleased(ray::Mouse::MOUSE_BUTTON_RIGHT))
        m_eventManager.drop("Mouse_RightClick_Released");
}

void GameScene::onUpdate()
{
    event();
    for (auto& [_, managerName] : m_managerLayer) {
        auto& sys = m_managerMap[managerName];
        if (!sys->isActive())
            continue;
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