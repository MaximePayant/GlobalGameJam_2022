/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectangleShapeManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECTANGLESHAPEMANAGER_HPP__
#define __RECTANGLESHAPEMANAGER_HPP__

#include "SW/Manager.hpp"
#include "RectangleShape.hpp"

class RectangleShapeManager
    :   public sw::AManager<RectangleShape>
{

    public:
        using sw::AManager<RectangleShape>::AManager;
        ~RectangleShapeManager() = default;

        void onUpdate() override;

        std::string type() const override { return ("RectangleShapeManager"); }

};

#endif // __RECTANGLESHAPEMANAGER_HPP__