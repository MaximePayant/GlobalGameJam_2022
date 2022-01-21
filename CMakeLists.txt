##
## EPITECH PROJECT, 2021
## Tek2
## File description:
## CMakeLists.txt
##

## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.18...3.20 )
set( CMAKE_BUILD_TYPE Release ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ABS_PATH}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
## <=====================================>


## PROJECT VAR
## <=====================================>
project( GGJ-2022
    VERSION
        1.0
    DESCRIPTION
        "Project for Global Game Jam 2022"
)

if (WIN32)
    message("Windows system detected prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message("Unix system detected prepare project...")
    include(.cmake_linux.cmake)
endif()