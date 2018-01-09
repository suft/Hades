#include "Codex.hpp"

namespace sufy { namespace utils {

    std::unordered_map<std::string, std::shared_ptr<sf::Font>> Codex::fonts;

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
}}
