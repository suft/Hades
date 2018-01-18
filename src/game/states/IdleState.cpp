#include "IdleState.hpp"

namespace sufy { namespace game { namespace states {

    IdleState::IdleState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode): State<sf::RenderWindow>(machine, adapter, mode) {
        this->background = sf::Color::Black;
        std::string names[] = {"Play", "Options", "Help", "Quit"};
        sufy::graphics::ActionColours colours = {
            {
                sf::Color::White,
                sf::Color::White
            },
            {
                sufy::constant::SLATEGREY,
                sufy::constant::SLATEGREY
            },
            {
                sf::Color(180, 222, 226),
                sf::Color(180, 222, 226)
            }
        };

        sf::Text text = sufy::utils::Text(
                "Hades",
                *sufy::utils::Codex::AcquireFont("Gelio.ttf"),
                300.0f,
                3.5,
                sf::Color(223, 151, 83),
                sf::Color(223, 151, 83)
        );

        this->menu.add(std::shared_ptr<sufy::window::gui::TextView>(new sufy::window::gui::TextView(
                250,
                text
        )));

        for (int i = 0; i < sizeof(names)/sizeof(names[0]); ++i) {
            sf::Text temp = sufy::utils::Text(
                    names[i],
                    *sufy::utils::Codex::AcquireFont("Gelio.ttf"),
                    120.0f,
                    1.5f,
                    sf::Color(),
                    sf::Color()
            );
            this->menu.add(std::shared_ptr<sufy::window::gui::Button>(new sufy::window::gui::Button(
                    550 + (i * 130),
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
