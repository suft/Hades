#pragma once

#include <SFML/Graphics.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../window/gui/TextView.hpp"
#include "../../utils/Misc.hpp"
#include "../../utils/Codex.hpp"
#include "../../window/gui/Menu.hpp"
#include "../../window/gui/Button.hpp"
#include "../../graphics/ActionColours.hpp"

namespace sufy { namespace game { namespace states {

    class IdleState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
        sufy::window::gui::Menu menu;
    public:
        IdleState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace);

        IdleState(const IdleState&) = delete;

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
