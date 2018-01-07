cmake_minimum_required(VERSION 3.9)
project(Sufy)

set(CMAKE_CXX_STANDARD 14)

set(SFML_LIB_PATH /usr/local/lib)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++14")
set(CXX_LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
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
# WINDOW NAMESPACE
file(GLOB WINDOW_HPP src/window/*.hpp)
file(GLOB WINDOW_CPP src/window/*.cpp)

# WINDOW GUI NAMESPACE
file(GLOB WINDOW_GUI_HPP src/window/gui/*.hpp)
file(GLOB WINDOW_GUI_CPP src/window/gui/*.cpp)
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
        ${UTILS_HPP} ${UTILS_CPP}
        ${GAME_HPP} ${GAME_CPP}
        ${GAME_STATES_HPP} ${GAME_STATES_CPP}
        ${WINDOW_HPP} ${WINDOW_CPP}
        ${WINDOW_GUI_HPP} ${WINDOW_GUI_CPP})


####
#### RESOURCE FILES
####

#################################################
## FONTS
set(FONTS Polya.otf)
#################################################

foreach(RESOURCE ${FONTS})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

add_definitions(-DBUILD_${CMAKE_BUILD_TYPE})
message(STATUS "BUILDTYPE:" ${BUILD_TYPE})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window)
include_directories(${SFML_INCLUDE_DIR} include)
link_directories(${SFML_LIB_PATH})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
