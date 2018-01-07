#include "IdleState.hpp"

namespace sufy { namespace game { namespace states {

    IdleState::IdleState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace): State<sf::RenderWindow>(machine, adapter, replace) {
        this->background = sf::Color::Black;
    }

    void IdleState::pause() {}
    void IdleState::resume() {}

    void IdleState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
    }

    void IdleState::render() {
        this->adapter.clear(this->background);
        this->adapter.display();
    }

    void IdleState::handleEvents(const sf::Event &event) {
        switch (event.type) {
            case sf::Event::Closed:
                this->machine.quit();
                break;
            default:
                break;
        }
    }
}}}
