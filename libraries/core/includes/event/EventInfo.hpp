/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventInfo.hpp
** Description: [CHANGE]
*/

#ifndef __SHIPWRECK_EVENTINFO_HPP__
#define __SHIPWRECK_EVENTINFO_HPP__

#include "../concepts.hpp"

namespace sw
{

    class IEventInfo
    {
        public:
            virtual ~IEventInfo() = default;
    };

    class EventInfo
    {

        private:
            IEventInfo& event;

        public:
            explicit EventInfo(IEventInfo& info) : event{info} {}
            ~EventInfo() = default;

            template<ConcreteEventInfo Info>
            Info& getInfo()
            {
                return (dynamic_cast<Info&>(event));
            }

    }; // class EventInfo

} // namespace sw

#endif // __SHIPWRECK_EVENTINFO_HPP__
