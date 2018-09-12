#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

namespace sufy { namespace objects {

    class Block: public Object {
    protected:
        float size;
        int id;
        sf::Texture tex;
        sf::Sprite sprite;
    public:
        Block() = default;
        Block(float x, float y, float size, int id, sf::Texture tex);

        bool isCollidable();

        void update(float dt) override;
        void render(sf::RenderTarget &rt) override;

        sf::FloatRect getBounds() override;
    };

}}
