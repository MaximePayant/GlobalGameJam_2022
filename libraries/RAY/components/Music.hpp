/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Music.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MUSIC_HPP__
#define __RAYLIB_MODULE_MUSIC_HPP__

#include "RAYLIB/raylib.h"
#include "SW/Component.hpp"
#include "../RayLibModule_Config.hpp"
#include "../resources/Music.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT MusicStream : public sw::Component
    {
        private:
            std::map<std::string, std::shared_ptr<ray::RMusic>> m_music;
            float m_volume;
            float m_pitch;
            std::string m_playing;

        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            explicit MusicStream(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play the audio you want with the specified name
            ///
            /// \param name
            ////////////////////////////////////////////////////////////////////////////
            void play(std::string name);

            void pause();

            void stop();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Add audio on your components with specified name
            ///
            /// \param sound
            /// \param name
            /// \return the components
            MusicStream& addSound(std::string soundName, std::string name);

            MusicStream& setVolume(float volume);
            MusicStream& setVolumeDown(float volume);
            MusicStream& setVolumeUp(float volume);
            MusicStream& setPitch(float pitch);

            [[nodiscard]]std::shared_ptr<ray::RMusic> getMusic() const;
            [[nodiscard]]float getPitch() const;
            [[nodiscard]]float getVolume() const;
            [[nodiscard]] std::string type() const override;
    };
} // namespace ray

#endif //__RAYLIB_MODULE_MUSIC_HPP__
