/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: IEventListener.h
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_AEVENTLISTENER_H
#define SHIPWRECK_AEVENTLISTENER_H

#include <functional>
#include <string>

#include "../concepts.hpp"
#include "../Config.hpp"

namespace sw
{
    class IEventListener
    {

        public:
            virtual ~IEventListener() = default;

            virtual void catchEvent() = 0;
            virtual void catchEvent(EventInfo& info) = 0;

            virtual std::string linkedEntity() const = 0;

    }; //

}

#endif //SHIPWRECK_AEVENTLISTENER_H
