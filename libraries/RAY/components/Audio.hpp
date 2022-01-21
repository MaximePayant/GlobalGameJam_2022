/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Audio.hpp
** Description: [CHANGE]
*/

#ifndef RAYMODULE_RAYLIBMODULE_AUDIO_HPP
#define RAYMODULE_RAYLIBMODULE_AUDIO_HPP

#include "RAYLIB/raylib.h"
#include "SW/Component.hpp"
#include "../RayLibModule_Config.hpp"
#include "../resources/Sound.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT Audio : public sw::Component
    {
        private:
            std::map<std::string, std::shared_ptr<ray::RSound>> m_sound;
            float m_volume;
            float m_pitch;

        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            explicit Audio(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play the audio you want with the specified name
            ///
            /// \param name
            ////////////////////////////////////////////////////////////////////////////
            void play(const std::string& name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play the audio you want in the current thread with the specified name
            ///
            /// \param name
            ////////////////////////////////////////////////////////////////////////////
            void playSolo(const std::string& name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Add audio on your components with specified name
            ///
            /// \param sound
            /// \param name
            /// \return the components
            Audio& addSound(std::string soundName, std::string name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Return the length of the specified sound
            ///
            /// \param name
            /// \return length of the sound in seconds
            float getSoundTimeLength(const std::string& name);

            Audio& setVolume(float volume);
            Audio& setPitch(float pitch);

            [[nodiscard]] std::string type() const override;
    };
} // namespace ray

#endif //RAYMODULE_RAYLIBMODULE_AUDIO_HPP
