/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IComponent.hpp
*/

#ifndef __SHIPWRECK_ICOMPONENT_HPP__
#define __SHIPWRECK_ICOMPONENT_HPP__

#include "../concepts.hpp"

namespace sw
{

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual void setActive(bool value) = 0;
            virtual bool isActive() const = 0;
            virtual Entity& entity() const = 0;
            virtual std::string type() const = 0;
    };

}

#endif // __SHIPWRECK_ICOMPONENT_HPP__