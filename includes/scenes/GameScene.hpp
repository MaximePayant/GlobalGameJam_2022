/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SplashScreen.h
** Description: [CHANGE]
*/

#ifndef BOMBERSHIP_GAMESCENE_HPP
#define BOMBERSHIP_GAMESCENE_HPP

#include "SW/Scene.hpp"

class GameScene : public sw::AScene
{
    public:
        using sw::AScene::AScene;
        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        [[nodiscard]] std::string type() const override;

        void event();
};

#endif //BOMBERSHIP_GAMESCENE_HPP
