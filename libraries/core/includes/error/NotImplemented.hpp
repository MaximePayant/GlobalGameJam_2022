/*
** EPITECH PROJECT, 2021
** NotImplemented.hpp
** File description:
** NotImplemented.hpp
*/

#ifndef __SHIPWRECK_NOTIMPLEMENTED__HPP__
#define __SHIPWRECK_NOTIMPLEMENTED__HPP__

#include <string>
#include "Error.hpp"

namespace sw
{
    class NotImplemented : public sw::Error
    {
    private:
        const std::string m_message;
    public:
        NotImplemented(NotImplemented const&) = delete;
        NotImplemented(NotImplemented &&) = delete;
        NotImplemented& operator=(NotImplemented const &) = delete;
        NotImplemented& operator=(NotImplemented&&) = delete;

        NotImplemented();
        explicit NotImplemented(const std::string &message, std::string code);
    }; // class NotImplemented

} // namespace sw



#endif //__SHIPWRECK_NOTIMPLEMENTED__HPP__
