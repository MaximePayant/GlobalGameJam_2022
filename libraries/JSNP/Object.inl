/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Object.inl
*/

/*
    EMPLACE FRONT
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, T value)
{
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Null null)
{
    (void)null;
    m_tokens.push_front(std::make_pair(key, jsnp::Value()));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, int integer)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(integer)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, float decimal)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(decimal)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, bool boolean)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(boolean)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, std::string str)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(str)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Array array)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(array)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Object object)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(object)));
    return (m_tokens.front());
}


/*
    EMPLACE BACK
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, T value)
{
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Null null)
{
    (void)null;
    m_tokens.push_back(std::make_pair(key, jsnp::Value()));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, int integer)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(integer)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, float decimal)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(decimal)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, bool boolean)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(boolean)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, std::string str)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(str)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Array array)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(array)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Object object)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(object)));
    return (m_tokens.back());
}


/*
    EMPLACE AT
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, T value, unsigned index)
{
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Null null, unsigned index)
{
    (void)null;
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, null));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value()));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, int integer, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, integer));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(integer)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, float decimal, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, decimal));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(decimal)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, bool boolean, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, boolean));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(boolean)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, std::string str, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, str));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(str)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Array array, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, array));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(array)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Object object, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (emplace_back(key, object));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(object)));
    return (*it);
}


/*
    REMOVE
*/
inline void jsnp::Object::remove(const std::string& key)
{
    for (auto it = m_tokens.begin(); it != m_tokens.end(); it++)
        if (it->first == key) {
            m_tokens.erase(it);
            return;
        }
    throw std::exception();
}

/*
    INSERT
*/
inline jsnp::Token& jsnp::Object::insert_front(jsnp::Token& token)
{
    m_tokens.push_front(token);
    return (m_tokens.front());
}

inline jsnp::Token& jsnp::Object::insert_back(jsnp::Token& token)
{
    m_tokens.push_back(token);
    return (m_tokens.back());
}

inline jsnp::Token& jsnp::Object::insert_at(jsnp::Token& token, unsigned index)
{
    std::list<jsnp::Token>::iterator it;

    if (index > m_tokens.size())
        return (insert_back(token));
    else
        it = m_tokens.insert(std::next(m_tokens.begin(), index), token);
    return (*it);
}

/*
    OTHER
*/
inline jsnp::Token& jsnp::Object::operator[](const std::string& key)
{
    for (auto& obj : m_tokens)
        if (obj.first == key)
            return (obj);
    throw std::exception();
}