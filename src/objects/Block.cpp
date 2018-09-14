#include <iostream>
#include "Block.hpp"

namespace sufy { namespace objects {

    Block::Block(float x, float y, float size, int id, sf::Texture tex): Object({x, y}) {
        this->size = size;
        this->sprite.setPosition(x, y);
        this->sprite.scale(3.0, 3.0);
        this->tex = tex;
        this->id = id;
    }

    bool Block::isCollidable() {
        return not (this->id == 5);
    }

    bool Block::isBreakable() {
        return (this->id == 1 or this->id == 7 or this->id == 8);
    }

    bool Block::isVisible() {
        return this->visible;
    }

    void Block::destroy() {
        this->visible =false;
    }

    void Block::update(float dt)  {

    }

    void Block::render(sf::RenderTarget &rt) {
        if (visible) {
            this->sprite.setTexture(tex);
            rt.draw(this->sprite);

            if (DEBUGGING) {
                sf::RectangleShape bounds;
                bounds.setSize({this->size - 30, this->size - 30});
                bounds.setOutlineThickness(8.0f);
                bounds.setFillColor(sf::Color::Transparent);
                switch (this->id) {
                    case 6:
                    case 17:
                    case 18:
                    case 19:
                    case 21:
                    case 23:
                    case 24:
                    case 27:
                    case 29:
                    case 31:
                    case 32:
                    case 34:
                        bounds.setOutlineColor(sf::Color::Yellow);
                        break;
                    case 20:
                    case 4:
                    case 22:
                    case 26:
                    case 25:
                    case 28:
                    case 35:
                        bounds.setOutlineColor(sf::Color::Green);
                        break;
                    case 1:
                    case 7:
                    case 8:
                        bounds.setOutlineColor(sf::Color::White);
                        break;
                    case 5:
                        bounds.setOutlineColor(sf::Color::Red);
                        break;
                    default:
                        bounds.setOutlineColor(sf::Color::Transparent);
                        break;
                }
                bounds.setPosition(this->position.x + 15, this->position.y + 15);
                rt.draw(bounds);
            }
        }
    }

    sf::FloatRect Block::getBounds() {
        return { this->position, {this->size, this->size} };
    }

}}
