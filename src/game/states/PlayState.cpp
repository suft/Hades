#include "PlayState.hpp"

namespace sufy { namespace game { namespace states {

    PlayState::PlayState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode): State(machine, adapter, mode) {
        this->background = sf::Color::Black;
        this->world = sufy::objects::World(*sufy::utils::Codex::AcquireJSON("level_one.json"));
        this->player = std::make_shared<sufy::objects::Player>(9 * 96, 6 * 96, this->world.getHandler());
    }

    void PlayState::pause() {}
    void PlayState::resume() {}

    void PlayState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
        this->world.update(dt);
        this->player->update(dt);
        this->camera.move(this->player->getPos(), {0.2f, 0.2f});
    }

    void PlayState::render() {
        this->adapter.clear(this->background);
        this->camera.render(this->adapter);
        this->world.render(this->adapter);
        this->player->render(this->adapter);
        this->camera.reset(this->adapter);
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
