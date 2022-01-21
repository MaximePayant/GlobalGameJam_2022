/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Component.inl
** Description: [CHANGE]
*/

#ifndef SWENGINE_CORE_TESTS_COMPONENT_INL
#define SWENGINE_CORE_TESTS_COMPONENT_INL

inline sw::Component::Component(sw::Entity& entityRef)
    :   m_isActive{true},
        m_entity{entityRef}
{}

inline void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

inline bool sw::Component::isActive() const
{
    return (m_isActive);
}

inline sw::Entity& sw::Component::entity() const
{
    return (m_entity);
}

inline std::ostream& operator<<(std::ostream& os, const sw::Component& cpt )
{
    os << "Component [" << cpt.type() << "] of " << cpt.entity().name() << "\n";
    return (os);
}

#endif //SWENGINE_CORE_TESTS_COMPONENT_INL
