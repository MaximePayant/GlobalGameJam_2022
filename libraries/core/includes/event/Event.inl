/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Event.inl
*/

template <ConcreteComponent Cpt>
inline void sw::Event::subscribe(Cpt* cpt, void (Cpt::*call)())
{
    m_listenerList.emplace_front(std::make_shared<EventListener<Cpt>>(*cpt, call));
}

template <ConcreteComponent Cpt>
inline void sw::Event::subscribe(Cpt* cpt, void (Cpt::*call)(EventInfo&))
{
    m_listenerList.emplace_front(std::make_shared<EventListener<Cpt>>(*cpt, call));
}