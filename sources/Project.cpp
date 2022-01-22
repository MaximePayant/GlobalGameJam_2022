/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Project.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"
#include "Project.hpp"

#include "scenes/Menu.hpp"
#include "scenes/SplashScreen.hpp"
#include "scenes/GameScene.hpp"

void sw::CreateScenes()
{
    sw::Engine::createScene<SplashScreen>(std::string("SplashScreen"));
    sw::Engine::createScene<GameScene>(std::string("GameScene"));
    sw::Engine::createScene<Menu>(std::string("Menu"));
}