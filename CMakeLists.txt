## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.17...3.20 )
set( CMAKE_BUILD_TYPE Debug ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
## <=====================================>


## PROJECT VAR
## <=====================================>
project( Incaribus
        VERSION
        0.1
        DESCRIPTION
        "Example project to test ShipWreckEngine"
        LANGUAGES
        CXX
        )

if (WIN32)
    message("Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message("Linux system detected, prepare project...")
    include(.cmake_linux.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()