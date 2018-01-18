#include "MenuState.hpp"

namespace sufy { namespace game { namespace states {

    MenuState::MenuState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace) : State(machine, adapter, replace) {
        this->background = sf::Color::Black;
        std::string names[] = {"Play", "Options", "Help", "Quit"};
        sufy::constant::Callback callbacks[] = {
            std::bind(&MenuState::play, this),
            std::bind(&MenuState::options, this),
            std::bind(&MenuState::help, this),
            std::bind(&MenuState::quit, this)
        };
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
            sufy::constant::HEIGHT / 3,
            3.5,
            sf::Color(223, 151, 83),
            sf::Color(223, 151, 83)
        );

        this->menu.add(std::shared_ptr<sufy::window::gui::TextView>(new sufy::window::gui::TextView(
                sufy::constant::HEIGHT / 4,
                text
        )));

        for (int i = 0; i < sizeof(names)/sizeof(names[0]); ++i) {
            sf::Text temp = sufy::utils::Text(
                names[i],
                *sufy::utils::Codex::AcquireFont("Gelio.ttf"),
                sufy::constant::HEIGHT / 10,
                1.5f,
                sf::Color(),
                sf::Color()
            );
            this->menu.add(std::shared_ptr<sufy::window::gui::Button>(new sufy::window::gui::Button(
                (sufy::constant::HEIGHT / 2) + (i * (sufy::constant::HEIGHT / 9)),
                temp,
                colours,
                callbacks[i]
            )));
        }

        this->menu.finalize();
    }

    void MenuState::play() {
        this->after = std::unique_ptr<SplashState>(new SplashState(this->machine, this->adapter, true));
    }

    void MenuState::options() {}

    void MenuState::help() {}

    void MenuState::quit() {
        this->machine.quit();
    }

    void MenuState::pause() {}
    void MenuState::resume() {}

    void MenuState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
        this->menu.update(dt);
    }

    void MenuState::render() {
        this->adapter.clear(this->background);
        this->menu.render(this->adapter);
        this->adapter.display();
    }

    void MenuState::handleEvents(const sf::Event &event) {
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
