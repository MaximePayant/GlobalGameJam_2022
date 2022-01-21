/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AModule.hpp
*/

#ifndef __SHIPWRECK_ISYSTEM_HPP__
#define __SHIPWRECK_ISYSTEM_HPP__

#include <string>
#include <memory>
#include <ios>

#include "../Config.hpp"
#include "../concepts.hpp"

namespace sw
{

    class AModule
    {

        protected:
            bool m_isLoad;

        public:
            AModule();
            virtual ~AModule() = default;

            bool isLoad() const;
            [[nodiscard]] virtual std::string type() const = 0;

            virtual void initialize() = 0;
            virtual bool isOk() = 0;
            virtual void update() = 0;
            virtual void terminate() = 0;
            virtual std::unique_ptr<sw::AResources> createResourceInstance() = 0;

    }; // class AModule

    std::ostream& operator<<(std::ostream& os, const AModule& module);

    #include "AModule.inl"

} // namespace sw

#endif // __SHIPWRECK_ISYSTEM_HPP__