/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventListener.inl
 *
 * Description:
 * Implementation of EventListener functions
 */

template<ConcreteComponent Cpt>
inline sw::EventListener<Cpt>::EventListener(Cpt& obj, void (Cpt::*call)())
    :   m_cpt{obj},
        m_call{call}
{}

template<ConcreteComponent Cpt>
inline sw::EventListener<Cpt>::EventListener(Cpt& obj, void (Cpt::*call)(EventInfo&))
    :   m_cpt{obj},
        m_call{call}
{}

template<ConcreteComponent Cpt>
inline void sw::EventListener<Cpt>::catchEvent()
try
{
    auto& call = std::get<void (Cpt::*)()>(m_call);
    ((m_cpt).*call)();
}
catch (std::bad_variant_access&)
{
    sw::Speech::Warning(sw::Log::warningC40(FUNCTION, m_cpt.entity().name()));
}

template<ConcreteComponent Cpt>
inline void sw::EventListener<Cpt>::catchEvent(EventInfo& info)
try
{
    auto& call = std::get<void (Cpt::*)(EventInfo&)>(m_call);
    ((m_cpt).*call)(info);
}
catch (std::bad_variant_access&)
{
    sw::Speech::Warning(sw::Log::warningC40(FUNCTION, m_cpt.entity().name()));
}

template<ConcreteComponent Cpt>
inline std::string sw::EventListener<Cpt>::linkedEntity() const
{
    return (m_cpt.entity().name());
}