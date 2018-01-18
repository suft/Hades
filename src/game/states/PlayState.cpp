#include "PlayState.hpp"

namespace sufy { namespace game { namespace states {

    PlayState::PlayState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode): State(machine, adapter, mode) {
        this->background = sf::Color::Black;
    }

    void PlayState::pause() {}
    void PlayState::resume() {}

    void PlayState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
    }

    void PlayState::render() {
        this->adapter.clear(this->background);
        this->camera.render(this->adapter);
        this->adapter.display();
    }

    void PlayState::handleEvents(const sf::Event& event) {
        switch (event.type) {
            case sf::Event::Closed:
                this->machine.quit();
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Escape) {
                    this->pauseIntent();
                }
                break;
            case sf::Event::JoystickButtonPressed:
                if (sf::Joystick::isConnected(0) and event.joystickButton.button == sufy::constant::HOME_BUTTON) {
                    this->pauseIntent();
                }
            default:
                break;
        }
    }

    void PlayState::pauseIntent() {
        this->after = std::unique_ptr<sufy::game::states::PauseState>(new sufy::game::states::PauseState(this->machine, this->adapter, sufy::state::StateMode::ADD));
    }

}}}
