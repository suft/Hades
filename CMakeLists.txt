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

# CONST NAMESPACE
file(GLOB CONST_HPP src/constant/*.hpp)

# STATE NAMESPACE
file(GLOB STATE_HPP src/state/*.hpp)
file(GLOB STATE_CPP src/state/*.cpp)

# UTILS NAMESPACE
file(GLOB UTILS_HPP src/utils/*.hpp)
file(GLOB UTILS_CPP src/utils/*.cpp)

set(SOURCE_FILES src/Main.cpp
        ${CONST_HPP}
        ${STATE_HPP} ${STATE_CPP}
        ${UTILS_HPP} ${UTILS_CPP})

add_definitions(-DBUILD_${CMAKE_BUILD_TYPE})
message(STATUS "BUILDTYPE:" ${BUILD_TYPE})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window)
include_directories(${SFML_INCLUDE_DIR} include)
link_directories(${SFML_LIB_PATH})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
