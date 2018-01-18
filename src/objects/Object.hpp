#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace sufy { namespace objects {

    class Object {
    protected:
        sf::Vector2f position;
    public:
        Object() = default;

        virtual void update(float dt) = 0;
        virtual void render(sf::RenderTarget &rt) = 0;

        virtual sf::FloatRect getBounds() = 0;
    };
}}
