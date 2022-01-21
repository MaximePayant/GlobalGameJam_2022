/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sound.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_SOUND__
#define __RAYLIB_MODULE_SOUND__

#include "RAYLIB/raylib.h"
#include "../RayLibModule_Config.hpp"
#include "SW/Resources.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RSound : public sw::ISound
    {
        private:
            Sound m_sound;

        public:
            RSound() = default;
            explicit RSound(Sound music);
            ~RSound() noexcept override;

            Sound operator*();
    }; // class RSound

} // namespace ray

#endif //__RAYLIB_MODULE_SOUND__
