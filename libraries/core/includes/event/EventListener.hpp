/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventListener.hpp
** Description: [CHANGE]
*/

#ifndef __SHIPWRECK_EVENTLISTENER_HPP__
#define __SHIPWRECK_EVENTLISTENER_HPP__

#include <map>
#include <variant>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "IEventListener.hpp"
#include "../utils/Speech.hpp"

namespace sw
{

    template<ConcreteComponent Cpt>
    class SW_CORE_API_EXPORT EventListener
        :   public IEventListener
    {

        private:
            Cpt& m_cpt;
            std::variant<
                void (Cpt::*)(void),
                void (Cpt::*)(EventInfo&)
            > m_call;

        public:
            explicit EventListener(Cpt& obj, void (Cpt::*call)());
            explicit EventListener(Cpt& obj, void (Cpt::*call)(EventInfo&));
            ~EventListener() override = default;

            void catchEvent() override;
            void catchEvent(EventInfo& info) override;

            [[nodiscard]] std::string linkedEntity() const override;

    }; // class EventListener

    #include "EventListener.inl"

} // namespace sw

#endif //__SHIPWRECK_EVENTLISTENER_HPP__
