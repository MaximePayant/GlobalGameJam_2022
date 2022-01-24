/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventManager.hpp
** Description: [CHANGE]
*/

#ifndef __UNITESTS_EVENTMANAGER_HPP__
#define __UNITESTS_EVENTMANAGER_HPP__

#include <unordered_map>
#include <memory>
#include <string>
#include <set>

#include "../concepts.hpp"
#include "../Config.hpp"

#include "Event.hpp"

namespace sw
{
    class SW_CORE_API_EXPORT EventManager
    {
        private:
            std::unordered_map<std::string, std::shared_ptr<Event>> m_eventList;

        public:
            EventManager()
                :   m_eventList{}
            {}
            ~EventManager() = default;

            [[nodiscard]] bool hasEvent(std::string eventName) const;

            Event& create(std::string eventName);
            [[nodiscard]] Event& get(std::string eventName) const;
            [[nodiscard]] Event& operator[](std::string eventName) const;

            void drop(std::string eventName);
            void drop(std::string eventName, EventInfo& info);
            void drop(std::string eventName, std::set<std::string> target);
            void drop(std::string eventName, EventInfo& info, std::set<std::string> target);

    }; // class EventManager

    #include "EventManager.inl"

} // namespace

#endif // __UNITESTS_EVENTMANAGER_HPP__