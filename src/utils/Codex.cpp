#include "Codex.hpp"

namespace sufy { namespace utils {

    std::unordered_map<std::string, std::shared_ptr<sf::Font>> Codex::fonts;
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> Codex::textures;

    std::shared_ptr<sf::Font> Codex::AcquireFont(const std::string& name) {
        const auto i = fonts.find(name);
        if (i != fonts.end()) return i->second;
        else {
            auto font = std::make_shared<sf::Font>();
            font->loadFromFile(name);
            fonts.insert({name, font});
            return font;
        }
    }

    std::shared_ptr<sf::Texture> Codex::AcquireTexture(const std::string& name) {
        const auto i = textures.find(name);
        if (i != textures.end()) return i->second;
        else {
            auto texture = std::make_shared<sf::Texture>();
            texture->loadFromFile(name);
            textures.insert({name, texture});
            return texture;
        }
    }
}}
