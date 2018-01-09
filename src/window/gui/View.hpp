#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../../constant/Flags.hpp"

namespace sufy { namespace window { namespace gui {

    class View {
    protected:
        float height;
        float position;

    public:
        View(): position(0.0f), height(0.0f) {}
        View(float position, float height): position(position), height(height) {}

        virtual void update(float dt) = 0;
        virtual void render(sf::RenderTarget& rt) {}
    };
}}}
