#pragma once

#include <string>
#include <SFML/System.hpp>

#if defined(BUILD_Debug)
#define DEBUGGING          true
#elif defined(BUILD_Release)
#define DEBUGGING          false
#endif

namespace sufy { namespace constant {
    static const std::string NAME = "Sufy";
    static const std::string DEBUGGING_NAME = "Sufy Debugging";
    static const int WIDTH = 1920;
    static const int HEIGHT = 1080;
    static const sf::Vector2f DIMENSIONS = sf::Vector2f(WIDTH, HEIGHT);
    static const sf::Vector2f ORIGIN = sf::Vector2f(0.0f, 0.0f);
    static const sf::Vector2f CENTER = sf::Vector2f((float) WIDTH/2, (float) HEIGHT/2);
    static const float DEBUG_THICKNESS = 1.0f;
    static const sf::Color DEBUG_OUTLINE = sf::Color::Red;
    static const sf::Color DEBUG_FILL = sf::Color::Transparent;
}}
