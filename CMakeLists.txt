cmake_minimum_required(VERSION 3.9)
project(Sufy)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/sfml_dir")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++14")
set(CXX_LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system -lz")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CXX_LINKER_FLAGS}")

####
#### SOURCE FILES
####

#################################################
# CONST NAMESPACE
file(GLOB CONST_HPP src/constant/*.hpp)
#################################################

#################################################
# STATE NAMESPACE
file(GLOB STATE_HPP src/state/*.hpp)
file(GLOB STATE_CPP src/state/*.cpp)
#################################################

#################################################
# UTILS NAMESPACE
file(GLOB UTILS_HPP src/utils/*.hpp)
file(GLOB UTILS_CPP src/utils/*.cpp)
#################################################

#################################################
# OBJECTS NAMESPACE
file(GLOB OBJECTS_HPP src/objects/*.hpp)
file(GLOB OBJECTS_CPP src/objects/*.cpp)
#################################################

#################################################
# WINDOW NAMESPACE
file(GLOB WINDOW_HPP src/window/*.hpp)
file(GLOB WINDOW_CPP src/window/*.cpp)

# WINDOW GUI NAMESPACE
file(GLOB WINDOW_GUI_HPP src/window/gui/*.hpp)
file(GLOB WINDOW_GUI_CPP src/window/gui/*.cpp)
#################################################

#################################################
# GRAPHICS NAMESPACE
file(GLOB GRAPHICS_HPP src/graphics/*.hpp)
#################################################

#################################################
# PENNER NAMESPACE
file(GLOB PENNER_HPP src/penner/*.hpp)
file(GLOB PENNER_CPP src/penner/*.cpp)
#################################################

#################################################
# GAME NAMESPACE
file(GLOB GAME_HPP src/game/*.hpp)
file(GLOB GAME_CPP src/game/*.cpp)

## GAME STATES NAMESPACE
file(GLOB GAME_STATES_HPP src/game/states/*.hpp)
file(GLOB GAME_STATES_CPP src/game/states/*.cpp)

#################################################

set(SOURCE_FILES src/Main.cpp
        ${CONST_HPP}
        ${STATE_HPP}
        ${GRAPHICS_HPP}
        ${OBJECTS_HPP} ${OBJECTS_CPP}
        ${UTILS_HPP} ${UTILS_CPP}
        ${GAME_HPP} ${GAME_CPP}
        ${GAME_STATES_HPP} ${GAME_STATES_CPP}
        ${WINDOW_HPP} ${WINDOW_CPP}
        ${WINDOW_GUI_HPP} ${WINDOW_GUI_CPP}
        ${PENNER_HPP} ${PENNER_CPP} src/objects/Block.cpp src/objects/Block.hpp src/objects/Player.cpp src/objects/Player.hpp src/graphics/Animation.cpp src/graphics/Animation.hpp src/objects/Collectable.hpp src/objects/Destroyable.hpp src/objects/Collidable.hpp src/objects/Background.hpp)

####
#### RESOURCE FILES
####

#################################################
## IMAGES
set(TILESET 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34)
#################################################

foreach(RESOURCE ${TILESET})
    set(TILE "tile0${RESOURCE}.png")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/tiles/${TILE}
            ${CMAKE_CURRENT_BINARY_DIR}/${TILE} COPYONLY)
endforeach(RESOURCE)

#################################################
## IMAGES
set(IMAGES Logo.png)
#################################################

foreach(RESOURCE ${IMAGES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

#################################################
## TILESET
set(TILESET cellar.json)
#################################################

foreach(RESOURCE ${TILESET})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/tileset/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

#################################################
## MAPS
set(MAPS level_one.json)
#################################################

foreach(RESOURCE ${MAPS})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/map/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

#################################################
## SKELETON
set(SKELETON_RESOURCES
        IdleRight.png IdleLeft.png
        WalkRight.png WalkLeft.png
        ReactRight.png ReactLeft.png
        DeadRight.png DeadLeft.png
        HitRight.png HitLeft.png
        AttackRight.png AttackLeft.png)
#################################################

foreach(RESOURCE ${SKELETON_RESOURCES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/skeleton/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)


add_definitions(-DBUILD_${CMAKE_BUILD_TYPE})
message(STATUS "BUILDTYPE:" ${BUILD_TYPE})
find_package(SFML 2.5 REQUIRED COMPONENTS network audio graphics window)
include_directories(${SFML_INCLUDE_DIR} include)
link_directories(${SFML_LIB_PATH})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
