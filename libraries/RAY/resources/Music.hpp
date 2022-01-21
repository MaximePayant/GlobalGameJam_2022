/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Music.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MUSIC__
#define __RAYLIB_MODULE_MUSIC__

#include "RAYLIB/raylib.h"
#include "../RayLibModule_Config.hpp"
#include "SW/Resources.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RMusic : public sw::IMusic
    {
        private:
            Music m_music;

        public:
            RMusic() = delete;
            RMusic(RMusic&&) = delete;
            RMusic(const RMusic&) = delete;
            explicit RMusic(Music music);
            ~RMusic() noexcept override;

            Music operator*();
    }; // class RMusic

} // namespace ray

#endif //__RAYLIB_MODULE_MUSIC__
