/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_AUDIO_MANAGER_HPP__
#define __RAYLIB_MODULE_AUDIO_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Audio.hpp"
#include "../RayLibModule_Config.hpp"

namespace ray
{

    class RAY_GRAPH_MODULE_EXPORT AudioManager : public sw::AManager<Audio>
    {
    public:
        using sw::AManager<Audio>::AManager;

        void onUpdate() override {};
        [[nodiscard]] std::string type() const override { return (std::string("AudioManager")); };

    }; // class AudioManager

}

#endif //__RAYLIB_MODULE_AUDIO_MANAGER_HPP__
