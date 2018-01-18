#include "Application.hpp"

namespace sufy { namespace game {

    void Application::run() {
        this->window.create(
                sf::VideoMode(sufy::constant::WIDTH, sufy::constant::HEIGHT),
                (DEBUGGING)? sufy::constant::DEBUGGING_NAME : sufy::constant::NAME,
                sf::Style::Fullscreen
        );
        this->window.setVerticalSyncEnabled(true);
        this->window.setFramerateLimit(60);

        using namespace states;
        this->machine.run(std::unique_ptr<SplashState>(new SplashState(this->machine, this->window, true)));

        auto tp = std::chrono::steady_clock::now();
        while (this->machine.isRunning()) {
            const auto new_tp = std::chrono::steady_clock::now();
            float dt = std::chrono::duration<float>(new_tp - tp).count();
            tp = new_tp;
            this->machine.next();
            this->machine.update(dt);
            this->machine.render();
        }
    }
}}
