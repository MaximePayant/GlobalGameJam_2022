/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Resources.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_RESOURCES_HPP__
#define __RAYLIB_MODULE_RESOURCES_HPP__

#include <string>
#include <unordered_map>
#include <memory>

#include "SW/errors/Error.hpp"
#include "SW/Resources.hpp"
#include "../RayLibModule_Config.hpp"
#include "resourcesList.hpp"
#include "JSNP/jsnp.hpp"

namespace ray
{

    class RAY_GRAPH_MODULE_EXPORT Resources : public sw::AResources
    {

        private:
            std::unordered_map<std::string, std::string> m_neededTextures;
            std::unordered_map<std::string, std::string> m_neededSounds;
            std::unordered_map<std::string, std::string> m_neededFonts;
            std::unordered_map<std::string, std::string> m_neededModels;
            std::unordered_map<std::string, std::string> m_neededMusic;

            void loadTextures();
            void loadSounds();
            void loadFonts();
            void loadModels();
            void loadMusics();

        public:
            static class TexturesMap : private std::unordered_map<std::string, std::shared_ptr<ray::RTexture>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<ray::RTexture>>::operator[];
                    friend Resources;
            } m_textures;

            static class SoundsMap : private std::unordered_map<std::string, std::shared_ptr<ray::RSound>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<ray::RSound>>::operator[];
                    friend Resources;
            } m_sounds;

            static class FontsMap : private std::unordered_map<std::string, std::shared_ptr<ray::RFont>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<ray::RFont>>::operator[];
                    friend Resources;
            } m_fonts;

            static class ModelsMap : private std::unordered_map<std::string, std::shared_ptr<ray::RModel>>
            {
            public:
                using std::unordered_map<std::string, std::shared_ptr<ray::RModel>>::operator[];
                friend Resources;
            } m_models;

            static class MusicMap : private std::unordered_map<std::string, std::shared_ptr<ray::RMusic>>
            {
            public:
                using std::unordered_map<std::string, std::shared_ptr<ray::RMusic>>::operator[];
                friend Resources;
            } m_musics;

            Resources() = default;
            ~Resources();

            void loadResources() override;
            void unloadResources() override;

            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;

            static std::shared_ptr<ray::RTexture> getTexture(const std::string& textureName);
            static std::shared_ptr<ray::RSound> getSound(const std::string& soundName);
            static std::shared_ptr<ray::RMusic> getMusic(const std::string& musicName);
            static std::shared_ptr<ray::RModel> getModel(const std::string& modelName);
            static std::shared_ptr<ray::RFont> getFont(const std::string& fontName);
    }; // class Resources

} // namespace ray

#endif // __RAYLIB_MODULE_RESOURCES_HPP__