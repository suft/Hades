#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../constant/Flags.hpp"

namespace sufy { namespace window {

    class Camera {
    private:
        sf::View view;
    public:
        Camera();

        void reset(sf::RenderTarget& rt);
        void render(sf::RenderTarget& rt);
        void move(sf::Vector2f position, sf::Vector2f speed);
    };
}}
