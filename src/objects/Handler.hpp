#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Object.hpp"

namespace sufy { namespace objects {

    class Handler {
    public:
        std::vector<std::shared_ptr<Object>> objects;
    public:
        Handler() = default;

        void add(std::shared_ptr<Object> o);
        void remove(std::shared_ptr<Object> o);

        void update(float dt);
        void render(sf::RenderTarget& rt);
    };
}}
