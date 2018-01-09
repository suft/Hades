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
    static const sf::Color DEBUG_OUTLINE = sf::Color::White;
    static const sf::Color DEBUG_FILL = sf::Color::Transparent;

    static const sf::Color LIGHTGRAY = sf::Color(211, 211, 211);
    static const sf::Color SLATEGREY = sf::Color(112, 128, 144);
    static const sf::Color GREY = sf::Color(128, 128, 128);
    static const sf::Color DIMGREY = sf::Color(105, 105, 105);
    static const sf::Color DARKSLATEGREY = sf::Color(47, 79, 79);

    static const unsigned int A_BUTTON = 0;
    static const unsigned int B_BUTTON = 1;
    static const unsigned int X_BUTTON = 2;
    static const unsigned int Y_BUTTON = 3;
    static const unsigned int LB_BUTTON = 4;
    static const unsigned int RB_BUTTON = 5;
    static const unsigned int LEFT_JOYSTICK_BUTTON = 6;
    static const unsigned int RIGHT_JOYSTICK_BUTTON = 7;
    static const unsigned int START_BUTTON = 8;
    static const unsigned int BACK_BUTTON = 9;
    static const unsigned int HOME_BUTTON = 10;
    static const unsigned int UP_BUTTON = 11;
    static const unsigned int DOWN_BUTTON = 12;
    static const unsigned int LEFT_BUTTON = 13;
    static const unsigned int RIGHT_BUTTON = 14;
}}
