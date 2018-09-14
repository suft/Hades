#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <fstream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <nlohmann/json.hpp>

namespace sufy { namespace utils {

    class Codex {
    private:
        static std::unordered_map<std::string, std::shared_ptr<sf::Font>> fonts;
        static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
        static std::unordered_map<std::string, std::shared_ptr<nlohmann::json>> jsons;
    public:
        static std::shared_ptr<sf::Font> AcquireFont(const std::string& name);
        static std::shared_ptr<sf::Texture> AcquireTexture(const std::string& name);
        static std::shared_ptr<nlohmann::json> AcquireJSON(const std::string& name);
    };
}}
