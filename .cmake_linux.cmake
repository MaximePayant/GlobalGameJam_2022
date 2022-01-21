##
## EPITECH PROJECT, 2021
## Tek2
## File description:
## CMakeLists.txt
##

## PROJECT VAR
## <=====================================>
project( GGJ-2022
        VERSION
        1.0
        DESCRIPTION
        "Project for Global Game Jam 2022"
        LANGUAGES
        CXX
        )
set( EXEC GGJ-2022 )
set( EXT cpp )

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_SOURCE_DIR}/sources/
        ${CMAKE_SOURCE_DIR}/sources/scenes/
        ${CMAKE_SOURCE_DIR}/sources/script/
        ${CMAKE_SOURCE_DIR}/sources/script/SplashScreen/
        ${CMAKE_SOURCE_DIR}/sources/script/GameScene/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/libraries/
        ${CMAKE_SOURCE_DIR}/libraries/core/
        ${CMAKE_SOURCE_DIR}/includes/
        ${CMAKE_SOURCE_DIR}/includes/scenes/
        ${CMAKE_SOURCE_DIR}/includes/script/
        ${CMAKE_SOURCE_DIR}/includes/script/SplashScreen/
        ${CMAKE_SOURCE_DIR}/includes/script/GameScene/
        )
## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        SWEngine-Core
        SWEngine-RayLibModule
        raylib
        )
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/libraries/libJsnp.so
        ${CMAKE_SOURCE_DIR}/libraries/libSWEngine-Core.so
        ${CMAKE_SOURCE_DIR}/libraries/libSWEngine-RayLibModule.so
        ${CMAKE_SOURCE_DIR}/libraries/libraylib.so
        )
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})

## or SHARED LIB
# add_library(${EXEC} SHARED ${SRC})

## or STATIC LIB
# add_library(${EXEC} STATIC ${SRC})
## <=====================================>


## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PRIVATE ${INC_FOLDERS})
## <=====================================>

## ADD PARAMETER
## <=====================================>
if (UNIX)
    target_compile_options(${EXEC} PRIVATE -g3)
endif (UNIX)
## <=====================================>


## SHARED LIBRARY LINKING
## <=====================================>
list(LENGTH SHARED_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

foreach(ctr RANGE ${LIST_LEN})
    list(GET SHARED_LIB_NAME ${ctr} lib)
    list(GET SHARED_LIB_LOCATION ${ctr} loc)
    add_library(${lib} SHARED IMPORTED)
    set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            )
endforeach()
target_link_libraries(${EXEC}
        PUBLIC
        ${SHARED_LIB_NAME}
        )
## <=====================================>