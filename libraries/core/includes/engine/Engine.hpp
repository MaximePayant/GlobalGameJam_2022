/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.hpp
*/

#ifndef __SHIPWRECK_ENGINE_HPP__
#define __SHIPWRECK_ENGINE_HPP__

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <type_traits>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "../scene/AScene.hpp"
#include "../module/AModule.hpp"
#include "../utils/Speech.hpp"
#include "../Config.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Engine
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<AScene>> m_scenes;
            static std::string m_activeScene;
            static std::unique_ptr<AModule> m_module;
            static bool m_isLoad;
            static std::unordered_set<std::string> m_scenesToDelete;
            static std::string m_nextActiveScene;
            static bool m_moduleToDelete;

            static void deleteRequestedScenes();
            static void setRequestedActiveScene();

            static void executeDeleteModule();

        public:
            Engine() = delete;
            Engine(Engine&&) = delete;
            Engine(const Engine&) = delete;
            ~Engine() = default;

            static void initialize();
            static void update();
            static void terminate();

            static bool isLoad();


            template <ConcreteScene Scene>
            static Scene& createScene(const std::string& sceneName);

            template <ConcreteScene Scene>
            static Scene& getScene(const std::string& sceneName);
            static AScene& getScene(const std::string& sceneName);
            static std::unordered_map<std::string, std::unique_ptr<AScene>>& getScenes();

            template <ConcreteScene Scene>
            static Scene& activeScene();
            static AScene& activeScene();
            static std::string activeSceneName();
            static void setActiveSceneName(const std::string& newSceneName);

            static void deleteScene(const std::string& sceneName);
            static bool hasScene(const std::string& sceneName);
            static void eraseScenes();

            static void setActiveScene(const std::string& name);


            template <ConcreteModule Module>
            static Module& createModule();

            template <ConcreteModule Module>
            static Module& getModule();
            static AModule& getModule();

            static void deleteModule();
            static bool hasModule();

            static void display(std::ostream& os = std::cout, bool dispContent = false);
            static void setModule(std::unique_ptr<AModule>&& module);

    }; // class Engine

    #include "moduleFunction.inl"
    #include "sceneFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_ENGINE_HPP__