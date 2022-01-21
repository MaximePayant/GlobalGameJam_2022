/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BillBoard.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_BILLBOARD_HPP__
#define __RAYLIB_MODULE_BILLBOARD_HPP__

#include "SW/Component.hpp"
#include "../resources/Texture.hpp"

namespace ray
{
    class BillBoard : public sw::Component
    {
        private:
            std::shared_ptr<ray::RTexture> m_texture;
        public:
            BillBoard() = delete;
            ~BillBoard() = default;
            explicit BillBoard(sw::Entity &entityRef);

            BillBoard& setTexture(std::string name);

            [[nodiscard]] ray::RTexture& getTexture();
            [[nodiscard]] std::string type() const override;
    };

}

#endif //__RAYLIB_MODULE_BILLBOARD_HPP__
