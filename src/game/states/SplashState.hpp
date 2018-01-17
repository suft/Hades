#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../utils/Codex.hpp"
#include "../../penner/Fader.hpp"
#include "MenuState.hpp"

namespace sufy { namespace game { namespace states {

    class SplashState : public sufy::state::State<sf::RenderWindow> {
    private:
        float duration;
        sf::Color background;
        sf::Sprite logo;
        sufy::penner::Fader fader;
    public:
        SplashState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;
    private:
        void handleEvents(const sf::Event& event);

        void swapFader();
        void renderLogo(sf::RenderTarget& rt);
    };
}}}
