#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Block.hpp"
#include "Object.hpp"
#include "Handler.hpp"
#include "../graphics/Animation.hpp"

namespace sufy { namespace objects {

    class Player : public Object {
    private:
        enum class AnimationType {
            IdleRight, IdleLeft,
            WalkRight, WalkLeft,
            AttackRight, AttackLeft,
            HitRight, HitLeft,
            ReactRight, ReactLeft,
            DeadRight, DeadLeft

        };
        const float width = 48.0f;
        const float height = 96.0f;
        const float gravity = 0.45f;
        const float terminal = 10.0f;
        bool attacking = false;
        bool jumping = false;
        bool falling = true;
        int direction = 1;

        sf::Vector2f velocity;
        sf::Sprite sprite;
        Handler *handler;
        std::vector<sufy::graphics::Animation> animations;
        AnimationType currentAnimation;
    public:
        Player() = default;
        Player(float x, float y, Handler* handler);

        void update(float dt) override;
        void render(sf::RenderTarget &rt) override;
    private:
        void loadAnimations();
        void attackComplete();

        void collision();
        bool up();
        bool right();
        bool left();
        void input();
        bool attack();

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
