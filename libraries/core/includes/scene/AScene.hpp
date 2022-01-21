/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** scene.hpp
*/

#ifndef __SHIPWRECK_ASCENE_HPP__
#define __SHIPWRECK_ASCENE_HPP__

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <memory>
#include <forward_list>
#include <type_traits>
#include <stack>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "../entity/IEntity.hpp"
#include "../manager/IManager.hpp"
#include "../resources/AResources.hpp"
#include "../event/EventManager.hpp"

#include "../error/Error.hpp"
#include "../utils/Speech.hpp"
#include "JSNP/jsnp.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT AScene
    {

        private:
            bool m_isLoad;

        protected:
            const std::string m_name;

            std::unordered_set<std::string> m_managersToDelete;
            std::unordered_set<std::string> m_entitiesToDelete;

            EventManager m_eventManager;
            std::unique_ptr<AResources> m_resources;

            class ManagerMap :
                private std::unordered_map<std::string, std::unique_ptr<IManager>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::operator[];

                friend AScene;
            } m_managerMap;

            class EntityMap :
                    public std::unordered_map<std::string, std::unique_ptr<IEntity>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::operator[];

                friend AScene;
            } m_entityMap;

            class ManagerLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AScene;
            } m_managerLayer;

            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

            void deleteRequestedEntities();
            void deleteRequestedManagers();

        public:
            AScene() = delete;
            AScene(AScene&&) = delete;
            AScene(const AScene&) = delete;
            explicit AScene(const std::string& sceneName);
            ~AScene() = default;

            [[nodiscard]] std::string name() const;
            [[nodiscard]] bool isLoad() const;
            virtual std::string type() const = 0;

            [[nodiscard]] sw::EventManager& eventManager();
            [[nodiscard]] std::unique_ptr<AResources>& resources();

            void load();
            void update();
            void unload();

            Entity& createEntity(const std::string& entityName);
            [[nodiscard]] Entity& getEntity(const std::string& entityName);
            [[nodiscard]] bool hasEntity(const std::string& entityName);
            void deleteEntity(const std::string& entityName);
            void eraseEntities();
            std::size_t entitiesCount() const;

            template <ConcreteManager Manager, typename... Args>
            Manager& createManager(const std::string& managerName, Args... args);
            template <ConcreteManager Manager>
            [[nodiscard]] Manager& getManager(const std::string& managerName);
            [[nodiscard]] IManager& getManager(const std::string& managerName);
            [[nodiscard]] bool hasManager(const std::string& managerName);
            void deleteManager(const std::string& managerName);
            void eraseManagers();
            std::size_t managersCount() const;

            void setLayer(const std::string& managerName, int layer);
            [[nodiscard]] int getLayer(const std::string managerName) const;

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);

            template<class T>
            void createScript(sw::Entity& entity);

            bool operator==(const sw::AScene& right) const {
                return (m_name == right.m_name);
            }

    }; // class AScene

    std::ostream& operator<<(std::ostream& os, const AScene& scene);

    #include "AScene.inl"
    #include "entityFunction.inl"
    #include "managerFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_ASCENE_HPP__