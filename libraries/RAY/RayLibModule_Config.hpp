/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RayLibModule_Config.hpp
** Description: [CHANGE]
*/

#ifndef RAYMODULE_RAYLIBMODULE_CONFIG_HPP
#define RAYMODULE_RAYLIBMODULE_CONFIG_HPP

#if defined(_WIN32)
    #define SW_GRAPH_MODULE_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define RAY_GRAPH_MODULE_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif
#else
    #error Unsupported system
#endif

#if defined(SW_GRAPH_MODULE_WINDOWS_SYSTEM)
    #define RAY_GRAPH_MODULE_EXPORT __declspec(dllexport)
    #define RAY_GRAPH_MODULE_IMPORT __declspec(dllimport)
#else
    #define RAY_GRAPH_MODULE_EXPORT
    #define RAY_GRAPH_MODULE_IMPORT
#endif

#endif //RAYMODULE_RAYLIBMODULE_CONFIG_HPP
