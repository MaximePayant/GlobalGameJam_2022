/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Value.inl
*/

inline jsnp::Value::Value()
    :   m_value(jsnp::Null()),
        m_type(NULL_PTR)
{}

inline jsnp::Value::Value(int integer)
    :   m_value(integer),
        m_type(INTEGER)
{}

inline jsnp::Value::Value(float decimal)
    :   m_value(decimal),
        m_type(DECIMAL)
{}

inline jsnp::Value::Value(bool boolean)
    :   m_value(boolean),
        m_type(BOOL)
{}

inline jsnp::Value::Value(std::string str)
    :   m_value(str),
        m_type(STRING)
{}

inline jsnp::Value::Value(Array array)
    :   m_value(array),
        m_type(ARRAY)
{}

inline jsnp::Value::Value(Object object)
    :   m_value(object),
        m_type(OBJECT)

{}

template <>
inline int& jsnp::Value::value()
{ return (std::get<int>(m_value)); }

template <>
inline float& jsnp::Value::value()
{ return (std::get<float>(m_value)); }

template <>
inline bool& jsnp::Value::value()
{ return (std::get<bool>(m_value)); }

template <>
inline jsnp::Null& jsnp::Value::value()
{ return (std::get<jsnp::Null>(m_value)); }

template <>
inline std::string& jsnp::Value::value()
{ return (std::get<std::string>(m_value)); }

template <>
inline jsnp::Array& jsnp::Value::value()
{ return (std::get<jsnp::Array>(m_value)); }

template <>
inline jsnp::Object& jsnp::Value::value()
{ return (std::get<jsnp::Object>(m_value)); }

template <typename T>
inline T& jsnp::Value::operator=(const T& right)
{ return (std::get<T>(m_value) = right); };

template <typename T>
inline T& jsnp::Value::operator+=(const T& right)
{ return (std::get<T>(m_value) += right); };

template <typename T>
inline T& jsnp::Value::operator-=(const T& right)
{ return (std::get<T>(m_value) -= right); };

template <typename T>
inline T& jsnp::Value::operator*=(const T& right)
{ return (std::get<T>(m_value) *= right); };

template <typename T>
inline T& jsnp::Value::operator/=(const T& right)
{ return (std::get<T>(m_value) /= right); };

template <typename T>
inline T& jsnp::Value::operator%=(const T& right)
{ return (std::get<T>(m_value) %= right); };


template <typename T>
inline T jsnp::Value::operator+(const T& right) const
{ return (std::get<T>(m_value) + right); };

template <typename T>
inline T jsnp::Value::operator-(const T& right) const
{ return (std::get<T>(m_value) - right); };

template <typename T>
inline T jsnp::Value::operator*(const T& right) const
{ return (std::get<T>(m_value) * right); };

template <typename T>
inline T jsnp::Value::operator/(const T& right) const
{ return (std::get<T>(m_value) / right); };

template <typename T>
inline T jsnp::Value::operator%(const T& right) const
{ return (std::get<T>(m_value) % right); };


template <typename T>
inline bool jsnp::Value::operator&&(const T& right) const
{ return (std::get<T>(m_value) && right); };

template <typename T>
inline bool jsnp::Value::operator||(const T& right) const
{ return (std::get<T>(m_value) || right); };

template <typename T>
inline bool jsnp::Value::operator==(const T& right) const
{ return (std::get<T>(m_value) == right); };

template <>
inline bool jsnp::Value::operator==(const jsnp::Value& right) const
{
    if (m_type != right.m_type)
        return (false);
    switch (m_type)
    {
        case INTEGER:
            return (std::get<int>(m_value) == std::get<int>(right.m_value));
        case DECIMAL:
            return (std::get<float>(m_value) == std::get<float>(right.m_value));
        case BOOL:
            return (std::get<bool>(m_value) == std::get<bool>(right.m_value));
        case STRING:
            return (std::get<std::string>(m_value) == std::get<std::string>(right.m_value));
        case ARRAY:
            return (std::get<jsnp::Array>(m_value) == std::get<jsnp::Array>(right.m_value));
        case OBJECT:
            return (std::get<jsnp::Object>(m_value) == std::get<jsnp::Object>(right.m_value));
    }
    return (true);
}

inline bool jsnp::Value::operator!() const
{
    switch (m_type)
    {
        case INTEGER:
            return (!std::get<int>(m_value));
        case DECIMAL:
            return (!std::get<float>(m_value));
        case BOOL:
            return (!std::get<bool>(m_value));
        case STRING:
            return (std::get<std::string>(m_value).empty());
        case ARRAY:
            return (!std::get<jsnp::Array>(m_value).size());
        case OBJECT:
            return (!std::get<jsnp::Object>(m_value).size());
    }
    return (true);
}