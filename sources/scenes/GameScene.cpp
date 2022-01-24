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
#include "script/GameScene/Ghost1.hpp"
#include "script/GameScene/Ghost2.hpp"
#include "script/GameScene/TextDisplay.hpp"

#include "RectMouseCollider.hpp"
#include "RectMCManager.hpp"

#include "ObjCollider.hpp"
#include "ObjColliderManager.hpp"
#include "InteractiveObj/Poster.hpp"
#include "InteractiveObj/Drawer.hpp"
#include "InteractiveObj/Pen.hpp"
#include "InteractiveObj/AlarmClock.hpp"
#include "InteractiveObj/PoemeFrag1.hpp"
#include "InteractiveObj/PoemeFrag2.hpp"
#include "InteractiveObj/SimpleNote.hpp"
#include "InteractiveObj/Note.hpp"
#include "InteractiveObj/BallNote.hpp"
#include "InteractiveObj/BreashWall.hpp"
#include "InteractiveObj/Hook.hpp"
#include "InteractiveObj/Package.hpp"
#include "InteractiveObj/Box.hpp"
#include "InteractiveObj/Ball.hpp"
#include "InteractiveObj/Lens.hpp"
#include "InteractiveObj/Pillow.hpp"

#include "RectangleShapeManager.hpp"
#include "ButtonTest.hpp"

#include "EventInfo/MousePosition.hpp"
#include "EventInfo/ShowText.hpp"
#include "Mainchar.hpp"

void GameScene::onLoad()
{
    m_dialogue.loadFile("resources/dialogues.json");
    createManager<ray::TransformManager>("TransformManager");
    createManager<ray::MeshManager>("MeshManager");
    auto& scriptFact = createManager<sw::AScriptFact>("ScriptManager");
    createManager<ray::CameraManager>("CameraManager");
    createManager<ray::MusicManager>("MusicManager");
    createManager<ray::AudioManager>("AudioManager");
    createManager<ray::SpriteManager>("SpriteManager");
    createManager<ray::TextManager>("TextManager");
    createManager<ObjColliderManager>("ObjColliderManager").isDebuging = false;

    m_eventManager.create("Mouse_LeftClick_Pressed");
    m_eventManager.create("Mouse_RightClick_Pressed");
    m_eventManager.create("Mouse_LeftClick_Released");
    m_eventManager.create("Mouse_RightClick_Released");
    m_eventManager.create("ChangeWorld");
    eventManager().create("Start");
    eventManager().create("Update");
    eventManager().create("ShowText");
    eventManager().create("HideText");

    auto& obama = createEntity("Obama");
    auto& camera = createEntity("MainCamera");
    auto& music = createEntity("MusicManager");
    auto& loop = createEntity("MusicLoop");
    createEntity("ObjPoster");
    createEntity("ObjDrawer");
    createEntity("ObjPen");
    createEntity("ObjAlarmClock");
    createEntity("ObjPoemeFrag1");
    createEntity("ObjPoemeFrag2");
    createEntity("ObjSimpleNote");
    createEntity("ObjNote");
    createEntity("ObjBallNote");
    createEntity("ObjBreashWall");
    createEntity("ObjHook");
    createEntity("ObjPackage");
    createEntity("ObjBox");
    createEntity("ObjBall");
    createEntity("ObjLens");
    createEntity("ObjPillow");
    auto& mainChar = createEntity("MainChar");
    auto& textDisplay = createEntity("TextDisplay");

    setLayer("MeshManager", 0);
    setLayer("SpriteManager", 1);
    setLayer("TextManager", 2);

    scriptFact.createComponent<Poster>("ObjPoster");
    scriptFact.createComponent<Drawer>("ObjDrawer");
    scriptFact.createComponent<Pen>("ObjPen");
    scriptFact.createComponent<AlarmClock>("ObjAlarmClock");
    scriptFact.createComponent<PoemeFrag1>("ObjPoemeFrag1");
    scriptFact.createComponent<PoemeFrag2>("ObjPoemeFrag2");
    scriptFact.createComponent<SimpleNote>("ObjSimpleNote");
    scriptFact.createComponent<Note>("ObjNote");
    scriptFact.createComponent<BallNote>("ObjBallNote");
    scriptFact.createComponent<BreashWall>("ObjBreashWall");
    scriptFact.createComponent<Hook>("ObjHook");
    scriptFact.createComponent<Package>("ObjPackage");
    scriptFact.createComponent<Box>("ObjBox");
    scriptFact.createComponent<Ball>("ObjBall");
    scriptFact.createComponent<Lens>("ObjLens");
    scriptFact.createComponent<Pillow>("ObjPillow");

    textDisplay.createComponent<TextDisplay>("ScriptManager");
    mainChar.createComponent<MainChar>("ScriptManager");
    music.createComponent<MainMusic>("ScriptManager");
    loop.createComponent<LoopMusic>("ScriptManager");
    obama.createComponent<Obama>("ScriptManager");
    camera.createComponent<ray::RCamera>("CameraManager").setTarget(21.5, 0, -25).setPosition(21.5, 17, -25).setUp(8, 1, 0);

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
        m_eventManager.drop("Mouse_LeftClick_Pressed", info);
        m_eventManager.drop("HideText");
    }
    else if (ray::Input::IsMouseButtonReleased(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_eventManager.drop("Mouse_LeftClick_Released");

    if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_RIGHT)) {
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
    if (ray::Input::GetKeyReleased(ray::KEY_SPACE))
        eventManager().drop("HideText");
}

void GameScene::onUnload()
{

}

std::string GameScene::type() const
{
    return ("GameScene");
}