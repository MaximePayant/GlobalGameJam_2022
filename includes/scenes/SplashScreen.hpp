/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SplashScreen.h
** Description: [CHANGE]
*/

#ifndef BOMBERSHIP_SPLASHSCREEN_HPP
#define BOMBERSHIP_SPLASHSCREEN_HPP

#include "SW/Scene.hpp"

class SplashScreen : public sw::AScene
{
    public:
        using sw::AScene::AScene;
        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        [[nodiscard]] std::string type() const override;
};

#endif //BOMBERSHIP_SPLASHSCREEN_HPP
