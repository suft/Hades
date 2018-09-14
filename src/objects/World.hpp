#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include <nlohmann/json.hpp>
#include "Handler.hpp"
#include "Block.hpp"
#include "../utils/Codex.hpp"

namespace sufy { namespace objects {

    class World {
    private:
        Handler handler;
        int width;
        int height;
        int tw;
        int th;
        std::unordered_map<int, std::string> tiles;
    public:
        World() = default;
        World(nlohmann::json json);

        void load();
        void reset();

        void update(float dt);
        void render(sf::RenderTarget& rt);

        Handler* getHandler();
    };
}}
