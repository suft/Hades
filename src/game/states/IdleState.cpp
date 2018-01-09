#include "IdleState.hpp"

namespace sufy { namespace game { namespace states {

    IdleState::IdleState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace): State<sf::RenderWindow>(machine, adapter, replace) {
        this->background = sf::Color::Black;
        std::string names[] = {"Title", "Play", "Options", "Quit"};
        sufy::graphics::ActionColours colours = {
            {
                sf::Color::Green,
                sf::Color::Red
            },
            {
                sf::Color::Blue,
                sf::Color::Red
            },
            {
                sf::Color::Yellow,
                sf::Color::Red
            }
        };

        sf::Text text = sufy::utils::Text(
                "Sufy",
                *sufy::utils::Codex::AcquireFont("Polya.otf"),
                200.0f,
                3.5,
                sf::Color::Cyan,
                sf::Color::Magenta
        );

        this->menu.add(std::shared_ptr<sufy::window::gui::TextView>(new sufy::window::gui::TextView(
                300,
                text
        )));

        for (int i = 0; i < 4; ++i) {
            sf::Text temp = sufy::utils::Text(
                    names[i],
                    *sufy::utils::Codex::AcquireFont("Polya.otf"),
                    100.0f,
                    1.5f,
                    sf::Color::Green,
                    sf::Color::Red
            );
            this->menu.add(std::shared_ptr<sufy::window::gui::Button>(new sufy::window::gui::Button(
                    500 + (i * 110),
                    temp,
                    colours,
                    [](){}
            )));
        }

        this->menu.finalize();
    }

    void IdleState::pause() {}
    void IdleState::resume() {}

    void IdleState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
        this->menu.update(dt);
    }

    void IdleState::render() {
        this->adapter.clear(this->background);
        this->menu.render(this->adapter);
        this->adapter.display();
    }

    void IdleState::handleEvents(const sf::Event &event) {
        switch (event.type) {
            case sf::Event::Closed:
                this->machine.quit();
                break;
            case sf::Event::KeyReleased:
                menu.handleInput(event);
                break;
            case sf::Event::JoystickButtonPressed:
                menu.handleInput(event);
            default:
                break;
        }
    }
}}}
