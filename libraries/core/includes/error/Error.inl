/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Error.inl
*/

inline sw::Error::Error(const std::string &message, const std::string &code)
    :   std::exception(),
        m_code(code),
        m_message(message)
{}

inline sw::Error::Error(const Log& log)
    :   std::exception(),
        m_code(log.code),
        m_message(log.message)
{}

inline sw::Error::Error(const sw::Error& error)
    :   std::exception(),
        m_code(error.m_code),
        m_message(error.m_message)
{}

inline const std::string& sw::Error::getMessage() const
{
    return (m_message);
}

inline const std::string& sw::Error::getCode() const
{
    return (m_code);
}

inline const char * sw::Error::what() const noexcept
{
    return (m_message.c_str());
}