/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** data_type.hpp
*/

#ifndef __JSNP_DATA_TYPE_HPP__
#define __JSNP_DATA_TYPE_HPP__

#include <string>
#include <utility>

namespace jsnp
{

    class Value;

    using Token = std::pair<std::string, Value>;

    std::ostream& operator<<(std::ostream& os, const jsnp::Token& token);

    enum Type
    {
        NULL_PTR,
        INTEGER,
        DECIMAL,
        BOOL,
        STRING,
        ARRAY,
        OBJECT
    };

    struct Null {};

    inline bool operator==(const jsnp::Null left, const jsnp::Null right)
    { return (true); }

} // namespace jsnp

#endif // __JSNP_DATA_TYPE_HPP__