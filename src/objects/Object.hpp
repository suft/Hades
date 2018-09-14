#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "../constant/Flags.hpp"

namespace sufy { namespace objects {

    class Object {
    protected:
        sf::Vector2f position;
    public:
        Object() = default;

        inline Object(const sf::Vector2f& position) {
            this->position = position;
        }

        inline sf::Vector2f getPos() {
            return this->position;
        }

        virtual void update(float dt) = 0;
        virtual void render(sf::RenderTarget &rt) = 0;

        virtual sf::FloatRect getBounds() = 0;
    };
}}
