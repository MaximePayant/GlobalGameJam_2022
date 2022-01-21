/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BillBoardManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_BILLBOARD_MANAGER_HPP__
#define __RAYLIB_MODULE_BILLBOARD_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/BillBoard.hpp"

namespace ray
{
    class BillBoardManager : public sw::AManager<BillBoard>
    {
        public:
            using AManager<BillBoard>::AManager;
            void onUpdate() override;
            [[nodiscard]] std::string type() const override;
    }; // class BillBoardManager

} // namespace ray

#endif //__RAYLIB_MODULE_BILLBOARD_MANAGER_HPP__
