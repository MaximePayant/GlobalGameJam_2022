/*
** Creative Rift Project, 2022
**
** File description:
** Config.hpp
*/

#ifndef JSONPARSER_CONFIG_HPP
#define JSONPARSER_CONFIG_HPP

#if defined(_WIN32)
    #define JSONPARSER_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define JSONPARSER_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif

#else

    #error Unsupported system
#endif

#if defined(JSONPARSER_WINDOWS_SYSTEM)
    #define JSONPARSER_API_EXPORT __declspec(dllexport)
    #define JSONPARSER_API_IMPORT __declspec(dllimport)
#else
    #define JSONPARSER_API_EXPORT
    #define JSONPARSER_API_IMPORT
#endif

#endif //JSONPARSER_CONFIG_HPP
