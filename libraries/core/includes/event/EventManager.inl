/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** EventManager.inl
*/

inline bool sw::EventManager::hasEvent(std::string eventName) const
{
    return (m_eventList.contains(eventName));
}