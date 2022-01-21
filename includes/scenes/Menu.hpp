/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Menu.hpp
** Description: [CHANGE]
*/

#include "SW/Scene.hpp"

#ifndef INCARIBUS_MENU_HPP
#define INCARIBUS_MENU_HPP

class Menu : public sw::AScene {
    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        std::string type() const override { return ("Menu"); }

        void event();
};

#endif //INCARIBUS_MENU_HPP