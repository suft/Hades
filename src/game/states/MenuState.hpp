#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../window/gui/Menu.hpp"
#include "../../utils/Misc.hpp"
#include "../../utils/Codex.hpp"
#include "PlayState.hpp"

namespace sufy { namespace game { namespace states {

    class MenuState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
        sufy::window::gui::Menu menu;
    public:
        MenuState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;

        void playIntent();
        void optionsIntent();
        void helpIntent();
        void quitIntent();
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
