#include "PauseState.hpp"

namespace sufy { namespace game { namespace  states {

    PauseState::PauseState(state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode): State(machine, adapter, mode) {
        this->background = sf::Color::Black;
        int items = 4;
        std::string names[] = {"Resume", "Options", "Help", "Main Menu"};
        sufy::constant::Callback callbacks[] = {
            std::bind(&PauseState::resumeIntent, this),
            std::bind(&PauseState::optionsIntent, this),
            std::bind(&PauseState::helpIntent, this),
            std::bind(&PauseState::menuIntent, this)
        };
        this->menu.add(std::shared_ptr<sufy::window::gui::TextView>(new sufy::window::gui::TextView(
            sufy::constant::HEIGHT / 4,
            sufy::utils::Text(
                "Paused",
                *sufy::utils::Codex::AcquireFont("Gelio.ttf"),
                sufy::constant::HEIGHT / 3,
                3.5,
                sf::Color(223, 151, 83),
                sf::Color(223, 151, 83)
            )
        )));
        for (int i = 0; i < items; ++i) {
            this->menu.add(std::shared_ptr<sufy::window::gui::Button>(new sufy::window::gui::Button(
                (sufy::constant::HEIGHT / 2) + (i * (sufy::constant::HEIGHT / 9)),
                sufy::utils::Text(
                    names[i],
                    *sufy::utils::Codex::AcquireFont("Gelio.ttf"),
                    sufy::constant::HEIGHT / 10,
                    1.5f,
                    sf::Color(),
                    sf::Color()
                ),
                {
                    {sf::Color::White, sf::Color::White},
                    {sufy::constant::SLATEGREY, sufy::constant::SLATEGREY},
                    {sf::Color(180, 222, 226), sf::Color(180, 222, 226)}
                },
                callbacks[i]
            )));
        }
        this->menu.finalize();
    }

    void PauseState::resume() {}
    void PauseState::pause() {}

    void PauseState::resumeIntent() {
        this->machine.last();
    }
    void PauseState::optionsIntent() {}
    void PauseState::helpIntent() {}
    void PauseState::menuIntent() {
        this->after = std::unique_ptr<sufy::game::states::MenuState>(new sufy::game::states::MenuState(this->machine, this->adapter, sufy::state::StateMode::REPLACE_ALL));
    }

    void PauseState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
        this->menu.update(dt);
    }

    void PauseState::render() {
        this->adapter.clear(this->background);
        this->menu.render(this->adapter);
        this->adapter.display();
    }

    void PauseState::handleEvents(const sf::Event &event) {
        switch (event.type) {
            case sf::Event::Closed:
                this->machine.quit();
                break;
            case sf::Event::KeyReleased:
                this->menu.handleInput(event);
                break;
            case sf::Event::JoystickButtonPressed:
                this->menu.handleInput(event);
            default:
                break;
        }
    }

}}}
