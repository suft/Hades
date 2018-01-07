#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
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
        void render(sf::RenderTarget& rt) {
            if (DEBUGGING) {
                sf::FloatRect dimensions = getBounds();
                sf::RectangleShape bounds;
                bounds.setSize({dimensions.width, dimensions.height});
                bounds.setPosition(dimensions.left, dimensions.top);
                bounds.setOutlineThickness(sufy::constant::DEBUG_THICKNESS);
                bounds.setOutlineColor(sufy::constant::DEBUG_OUTLINE);
                bounds.setFillColor(sufy::constant::DEBUG_FILL);
                rt.draw(bounds);
            }
        }
    private:
        sf::FloatRect getBounds() {
            return {
                0,
                this->position - this->height/2,
                sufy::constant::DIMENSIONS.x,
                this->height
            };
        }
    };
}}}
