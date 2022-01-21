/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Event.hpp
** Description: [CHANGE]
*/

#ifndef __SHIPWRECK_EVENT_HPP__
#define __SHIPWRECK_EVENT_HPP__

#include <string>
#include <memory>
#include <forward_list>
#include <set>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "EventListener.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Event
    {
        private:
            std::forward_list<std::shared_ptr<IEventListener>> m_listenerList;
        public:
            Event()
                :   m_listenerList{}
            {}
            ~Event() = default;

            template <ConcreteComponent Cpt>
            void subscribe(Cpt* cpt, void (Cpt::*call)());
            template <ConcreteComponent Cpt>
            void subscribe(Cpt* cpt, void (Cpt::*call)(EventInfo&));

            void drop();
            void drop(EventInfo& info);
            void drop(std::set<std::string> target);
            void drop(EventInfo& info, std::set<std::string> target);

    }; // class Event

    #include "Event.inl"

} // namespace sw

#endif // __SHIPWRECK_EVENT_HPP__
