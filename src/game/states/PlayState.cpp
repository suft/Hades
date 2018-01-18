#include "PlayState.hpp"

namespace sufy { namespace game { namespace states {

    PlayState::PlayState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace): State(machine, adapter, replace) {}

    void PlayState::pause() {}
    void PlayState::resume() {}

    void PlayState::update(float dt) {

    }

    void PlayState::render() {
        this->adapter.clear();
        this->adapter.display();
    }

}}}
