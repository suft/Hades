#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <SFML/Graphics/Font.hpp>

namespace sufy { namespace utils {

    class Codex {
    private:
        static std::unordered_map<std::string, std::shared_ptr<sf::Font>> fonts;
    public:
        static std::shared_ptr<sf::Font> AcquireFont(const std::string& name);
    };
}}
