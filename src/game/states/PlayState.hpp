#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../../constant/Flags.hpp"
#include "../../state/State.hpp"
#include "../../state/StateMachine.hpp"
#include "../../window/Camera.hpp"
#include "../../utils/Codex.hpp"
#include "../../objects/World.hpp"
#include "PauseState.hpp"
#include "../../objects/Player.hpp"

namespace sufy { namespace game { namespace states {

    class PlayState : public sufy::state::State<sf::RenderWindow> {
    private:
        sf::Color background;
        sufy::objects::World world;
        std::shared_ptr<sufy::objects::Player> player;
        sufy::window::Camera camera;
    public:
        PlayState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode);

        void pause() override;
        void resume() override;

        void update(float dt) override;
        void render() override;

        void pauseIntent();
    private:
        void handleEvents(const sf::Event& event);
    };
}}}
