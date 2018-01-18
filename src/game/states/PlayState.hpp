#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../../state/State.hpp"

namespace sufy { namespace game { namespace states {

    class PlayState : public sufy::state::State<sf::RenderWindow> {
    private:
    public:
        PlayState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;
    };
}}}
