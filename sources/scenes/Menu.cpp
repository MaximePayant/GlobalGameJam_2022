/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Menu.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"

#include "RAY/RayLibModule.hpp"
#include "RAY/utils/Input.hpp"

#include "scenes/Menu.hpp"
#include "EventInfo/MousePosition.hpp"

void Menu::onLoad()
{
    m_eventManager.create("Mouse_LeftClick_Pressed");
    m_eventManager.create("Mouse_RightClick_Pressed");
    m_eventManager.create("Mouse_LeftClick_Released");
    m_eventManager.create("Mouse_RightClick_Released");

    m_eventManager.create("Start");
    m_eventManager.create("Update");
    m_eventManager.create("Unload");



    m_eventManager.drop("Start");
}

static void updateMousePosition(MousePosition_EventInfo& info)
{
    auto mpos = ray::Input::GetMousePosition();

    info.x = mpos.x;
    info.y = mpos.y;
}

void Menu::event()
{
    static MousePosition_EventInfo mpos{0, 0};
    static sw::EventInfo info{mpos};

    updateMousePosition(mpos);
    if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_eventManager.drop("Mouse_LeftClick_Pressed", info);
    else if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_eventManager.drop("Mouse_LeftClick_Released");
    if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_RIGHT))
        m_eventManager.drop("Mouse_RightClick_Pressed", info);
    else if (ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_RIGHT))
        m_eventManager.drop("Mouse_RightClick_Released");
}

void Menu::onUpdate()
{
    event();
    for (auto& [_, name] : m_managerLayer)
        m_managerMap[name]->update();
    m_eventManager.drop("Update");
}

void Menu::onUnload()
{
    m_eventManager.drop("Unload");
}