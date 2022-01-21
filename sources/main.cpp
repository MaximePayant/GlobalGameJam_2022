/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * main.cpp
 *
 * Description:
 * [Change]
 */

#include "SW/Engine.hpp"

int main()
{
    sw::Engine::initialize();
    sw::Speech::flush();

    auto& module = sw::Engine::getModule();

    while (module.isOk()) {
        sw::Engine::update();
        sw::Speech::flush();
    }
    sw::Engine::terminate();
    sw::Speech::flush();
    return (0);
}