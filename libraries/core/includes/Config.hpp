/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Config.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_CORE_CONFIG_HPP
#define SWENGINE_CORE_CONFIG_HPP

#define GRAPHICAL_MODULE

#if defined(_WIN32)
    #define SW_CORE_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define SW_CORE_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif

#else

    #error Unsupported system
#endif

#if defined(SW_CORE_WINDOWS_SYSTEM)
    #define SW_CORE_API_EXPORT __declspec(dllexport)
    #define SW_CORE_API_IMPORT __declspec(dllimport)
#else
    #define SW_CORE_API_EXPORT
    #define SW_CORE_API_IMPORT
#endif

#endif //SWENGINE_CORE_CONFIG_HPP
