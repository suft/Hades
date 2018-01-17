#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../window/gui/Menu.hpp"
#include "../../utils/Misc.hpp"
#include "../../utils/Codex.hpp"
#include "SplashState.hpp"

namespace sufy { namespace game { namespace states {

    class MenuState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
        sufy::window::gui::Menu menu;
    public:
        MenuState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;

        void play();
        void options();
        void help();
        void quit();
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
