#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "PauseState.hpp"

namespace sufy { namespace game { namespace states {

    class PlayState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
    public:
        PlayState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
