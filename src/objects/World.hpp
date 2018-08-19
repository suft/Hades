#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "Handler.hpp"

namespace sufy { namespace objects {

    class World {
    private:
        Handler handler;
    public:
        World() = default;

        void load();
        void reset();

        void update(float dt);
        void render(sf::RenderTarget& rt);
    };
}}
