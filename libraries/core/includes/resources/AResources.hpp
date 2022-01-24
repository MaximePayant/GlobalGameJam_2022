/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IResources.hpp
*/

#ifndef __SHIPWRECK_IRESOURCES_HPP__
#define __SHIPWRECK_IRESOURCES_HPP__

#include <vector>
#include <string>

namespace sw
{

    class AResources {
        public:
            std::vector<std::string> m_neededResource;

            virtual void loadResources() = 0;
            virtual void unloadResources() = 0;
            virtual void addNeededResource(const std::string& name, const std::string& path, const std::string& type) = 0;
    };

    class ITexture {
        public:
            virtual ~ITexture() = default;
    };

    class ISound {
        public:
            virtual ~ISound() = default;
    };

    class IFont {
        public:
            virtual ~IFont() = default;
    };

    class IMusic {
        public:
            virtual ~IMusic() = default;
    };

    class IModel {
        public:
            virtual ~IModel() = default;
    };

} // namespace sw

#endif // __SHIPWRECK_IRESOURCES_HPP__
