#pragma once

#include <SFML/System.hpp>

#if defined(BUILD_Debug)
#define DEBUGGING          true
#elif defined(BUILD_Release)
#define DEBUGGING          false
#endif

namespace sufy { namespace constant {
    static const int WIDTH = 1920;
    static const int HEIGHT = 1080;
    static const sf::Vector2f DIMENSIONS = sf::Vector2f(WIDTH, HEIGHT);
    static const sf::Vector2f ORIGIN = sf::Vector2f(0.0f, 0.0f);
}}
