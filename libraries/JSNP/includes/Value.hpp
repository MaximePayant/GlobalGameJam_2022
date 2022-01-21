/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Value.hpp
*/

#ifndef __JSNP_VALUE_HPP__
#define __JSNP_VALUE_HPP__

#include <string>
#include <variant>

#include "Config.hpp"
#include "Object.hpp"
#include "Array.hpp"

namespace jsnp
{

    class JSONPARSER_API_EXPORT Value
    {

        private:
            std::variant<
                Null,
                int,
                float,
                bool,
                std::string,
                Array,
                Object
            > m_value;
            Type m_type;

        public:
            Value();
            Value(int integer);
            Value(float decimal);
            Value(bool boolean);
            Value(std::string str);
            Value(Array array);
            Value(Object object);
            ~Value() = default;

            const Type& type() const { return (m_type); }
            template <typename T>
            T& value();

            friend std::ostream& operator<<(std::ostream& os, const Value& data);

            template <typename T>
            T& operator=(const T& right);
            template <typename T>
            T& operator+=(const T& right);
            template <typename T>
            T& operator-=(const T& right);
            template <typename T>
            T& operator*=(const T& right);
            template <typename T>
            T& operator/=(const T& right);
            template <typename T>
            T& operator%=(const T& right);

            template <typename T>
            T operator+(const T& right) const;
            template <typename T>
            T operator-(const T& right) const;
            template <typename T>
            T operator*(const T& right) const;
            template <typename T>
            T operator/(const T& right) const;
            template <typename T>
            T operator%(const T& right) const;

            template <typename T>
            bool operator&&(const T& right) const;
            template <typename T>
            bool operator||(const T& right) const;
            template <typename T>
            bool operator==(const T& right) const;

            bool operator!() const;

    }; // class Value

    std::ostream& operator<<(std::ostream& os, const Value& value);

} // namespace jsnp

#endif // __JSNP_VALUE_HPP__