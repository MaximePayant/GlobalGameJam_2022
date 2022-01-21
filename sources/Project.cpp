/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Project.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"
#include "Project.hpp"

#include "scenes/Main.hpp"
#include "scenes/SplashScreen.hpp"

void sw::CreateScenes()
{
    sw::Engine::createScene<SplashScreen>(std::string("SplashScreen"));
    sw::Engine::createScene<Main>(std::string("Main"));
}