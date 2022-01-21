/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TextManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_TEXT_MANAGER_HPP__
#define __RAYLIB_MODULE_TEXT_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Text.hpp"

namespace ray
{
    class TextManager : public sw::AManager<Text>
    {
        public:
            using sw::AManager<Text>::AManager;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;
    }; // class TextManager

} // namespace ray

#endif //__RAYLIB_MODULE_TEXT_MANAGER_HPP__
