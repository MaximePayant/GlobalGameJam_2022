/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** entityFunction.inl
*/

inline bool sw::AScene::hasEntity(const std::string& entityName)
{
    return (m_entityMap.contains(entityName));
}

inline std::size_t sw::AScene::entitiesCount() const
{
    return (m_entityMap.size());
}