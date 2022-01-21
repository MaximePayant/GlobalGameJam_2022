/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Data.inl
*/

inline static int key_tab(int offset = 0)
{
    static int tab = 0;

    tab += offset;
    return (tab);
}

inline void operator>>(std::ifstream& os, jsnp::Data& data)
{
    std::stringstream sstream;
    std::string str;
    std::size_t ctr = 0;

    if (!os)
        throw std::exception();
    sstream << os.rdbuf();
    str = sstream.str();
    if (!str.empty())
        data.clean_file(str);
    data.m_object = data.take_object(str, ctr);
}

inline std::ostream& operator<<(std::ostream& os, const jsnp::Array& array)
{
    os << "[" << std::endl;
    key_tab(1);
    for (unsigned ctr = 1; auto& value : array) {
        os << std::string(key_tab() * 4, ' ')
           << value;
        if (ctr < array.size())
            os << ",";
        os << std::endl;
        ctr += 1;
    }
    key_tab(-1);
    os << std::string(key_tab() * 4, ' ') << "]";
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const jsnp::Object& object)
{
    key_tab(1);
    os << "{" << std::endl;
    for (unsigned ctr = 1; auto& token : object) {
        os << token;
        if (ctr < object.size())
            os << ",";
        os << std::endl;
        ctr += 1;
    }
    key_tab(-1);
    os << std::string(key_tab() * 4, ' ') << "}";
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const jsnp::Value& value)
{
    std::visit(overloaded {
        [&](jsnp::Null)                { os << "null"; },
        [&](int integer)          { os << integer; },
        [&](float decimal)       { os << decimal; },
        [&](bool boolean)        { os << std::boolalpha << boolean; },
        [&](std::string str)     { os << "\"" << str << "\""; },
        [&](jsnp::Array array)   { os << array; },
        [&](jsnp::Object object) { os << object; },
    }, value.m_value);
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const jsnp::Data& data)
{
    os << data.m_object;
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const jsnp::Token& token)
{
    os << std::string(key_tab() * 4, ' ');
    os << "\"" << token.first << "\": "
       << token.second;
    return (os);
}

inline bool jsnp::Array::operator==(const jsnp::Array& right) const
{
    auto left_it = begin();
    auto right_it = right.begin();

    while (left_it != end()) {
        if (right_it == right.end()
        || *left_it != *right_it)
            return (false);
        left_it++;
        right_it++;
    }
    if (right_it != right.end())
        return (false);
    return (true);
}

inline bool jsnp::Object::operator==(const jsnp::Object& right) const
{
    auto left_it = begin();
    auto right_it = right.begin();

    while (left_it != end()) {
        if (right_it == right.end()
        || left_it->first != right_it->first
        || left_it->second != right_it->second)
            return (false);
        left_it++;
        right_it++;
    }
    if (right_it != right.end())
        return (false);
    return (true);
}