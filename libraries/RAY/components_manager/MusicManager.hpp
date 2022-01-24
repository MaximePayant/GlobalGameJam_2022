/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MusicManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MUSIC_MANAGER_HPP__
#define __RAYLIB_MODULE_MUSIC_MANAGER_HPP__

#include "SW/Manager.hpp"

#include "../RayLibModule_Config.hpp"
#include "../components/Music.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT MusicManager : public sw::AManager<MusicStream>
    {
        public:
            using AManager<MusicStream>::AManager;
            ~MusicManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;

    }; // class MusicManager

} // namespace ray

#endif //__RAYLIB_MODULE_MUSIC_MANAGER_HPP__
