#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../window/gui/Menu.hpp"
#include "../../utils/Misc.hpp"
#include "../../utils/Codex.hpp"
#include "MenuState.hpp"

namespace sufy { namespace game { namespace states {

    class PauseState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
        sufy::window::gui::Menu menu;
    public:
        PauseState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;

        void resumeIntent();
        void optionsIntent();
        void helpIntent();
        void menuIntent();
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
