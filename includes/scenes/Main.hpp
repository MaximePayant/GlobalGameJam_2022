/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.hpp
** Description: [CHANGE]
*/

#include "SW/Scene.hpp"

#ifndef INCARIBUS_MAIN_HPP
#define INCARIBUS_MAIN_HPP

class Main : public sw::AScene {
    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        std::string type() const override { return (""); }
};

#endif //INCARIBUS_MAIN_HPP
