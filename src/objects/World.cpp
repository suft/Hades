#include "World.hpp"
#include <iostream>

namespace sufy { namespace objects {

    World::World(nlohmann::json json) {
        this->width = json.value("width", 0);
        this->height = json.value("height", 0);
        this->tw = json.value("tilewidth", 0);
        this->th = json.value("tileheight", 0);
        for (auto set : json["tilesets"]) {
            std::string source = set.value("source", "");
            if (not source.empty()) {
                auto set = *sufy::utils::Codex::AcquireJSON(source);
                for (auto tile : set["tiles"].get<nlohmann::json::object_t>()) {
                    this->tiles.emplace(std::stoi(tile.first), tile.second["image"]);
                }
            }
        }
        for (auto layer : json["layers"]) {
            int w = layer.value("width", 0);
            int h = layer.value("height", 0);
            auto data = layer["data"];
            for (int i = 0; i < w * h; ++i) {
                int x = i % width;
                int y = (i / width) % height;
                int id = ((int) data[i]) - 1;
                auto search = this->tiles.find(id);
                if (search == this->tiles.end()) continue;
                this->handler.add(std::make_shared<Block>(x*96, y*96, 96, id, *sufy::utils::Codex::AcquireTexture(search->second)));
            }
        }
    }

    Handler* World::getHandler() {
        return &this->handler;
    }

    void World::load() {}

    void World::reset() {}

    void World::update(float dt) {
        handler.update(dt);
    }

    void World::render(sf::RenderTarget& rt) {
        handler.render(rt);
    }
}}
