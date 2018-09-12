#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Block.hpp"
#include "Object.hpp"
#include "Handler.hpp"

namespace sufy { namespace objects {

    class Player : public Object {
    private:
        const float width = 48.0f;
        const float height = 96.0f;
        const float gravity = 0.5f;
        const float terminal = 10.0f;
        bool jumping = false;
        bool falling = true;

        sf::Vector2f velocity;
        sf::Sprite sprite;
        Handler *handler;
    public:
        Player() = default;
        Player(float x, float y, Handler* handler);

        void update(float dt) override;
        void render(sf::RenderTarget &rt) override;
    private:
        void collision();
        bool up();
        bool right();
        bool left();
        void input();

        void renderBody(sf::RenderTarget& rt);
        void renderTop(sf::RenderTarget& rt);
        void renderBottom(sf::RenderTarget& rt);
        void renderRight(sf::RenderTarget& rt);
        void renderLeft(sf::RenderTarget& rt);

        sf::FloatRect getBounds() override;
        sf::FloatRect getBoundsBottom();
        sf::FloatRect getBoundsTop();
        sf::FloatRect getBoundsLeft();
        sf::FloatRect getBoundsRight();
    };

}}
