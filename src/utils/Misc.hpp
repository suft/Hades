#pragma once

#include <string>
#include <algorithm>
#include <SFML/Graphics/Text.hpp>

namespace sufy { namespace utils {

    template<class T>
    inline static const T& Clamp(const T &x, const T &lower, const T &upper) {
        return std::min(upper, std::max(x, lower));
    }

    inline static sf::Text Text(const std::string& string, const sf::Font &font, float size, float thickness, const sf::Color &outline, const sf::Color &fill) {
        sf::Text t;
        t.setString(string);
        t.setFont(font);
        t.setCharacterSize(size);
        t.setOutlineThickness(thickness);
        t.setOutlineColor(outline);
        t.setFillColor(fill);
        return t;
    }
}}
