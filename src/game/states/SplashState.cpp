#include "SplashState.hpp"

namespace sufy { namespace game { namespace states {

    SplashState::SplashState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, sufy::state::StateMode mode): State<sf::RenderWindow>(machine, adapter, mode) {
        this->logo = sf::Sprite(*sufy::utils::Codex::AcquireTexture("Logo.png"));
        auto scale = 0.45f;
        this->logo.setScale(scale, scale);
        auto global = this->logo.getGlobalBounds();
        this->logo.setPosition({
           (sufy::constant::WIDTH - global.width) / 2.0f,
           (sufy::constant::HEIGHT - global.height) / 2.0f
       });
        this->background = sf::Color::Black;
        this->fader = sufy::penner::Fader(
                sufy::penner::Fader::Direction::IN,
                2.0f,
                [](float){},
                std::bind(&sufy::game::states::SplashState::renderLogo, this, std::placeholders::_1),
                std::bind(&sufy::game::states::SplashState::swapFader, this)
        );
    }

    void SplashState::pause() {}

    void SplashState::resume() {}

    void SplashState::update(float dt) {
        sf::Event event;
        while (this->adapter.pollEvent(event)) this->handleEvents(event);
        if (this->fader.getDirection() == sufy::penner::Fader::Direction::OUT and this->fader.isComplete()) {
            this->after = std::unique_ptr<sufy::game::states::MenuState>(new sufy::game::states::MenuState(this->machine, this->adapter, sufy::state::StateMode::REPLACE_TOP));
        }
        this->fader.update(dt);
    }

    void SplashState::render() {
        this->adapter.clear(this->background);
        this->fader.render(this->adapter);
        this->adapter.display();
    }

    void SplashState::renderLogo(sf::RenderTarget &rt) {
        rt.draw(this->logo);
    }

    void SplashState::swapFader() {
        if (this->fader.getDirection() == sufy::penner::Fader::Direction::IN and this->fader.isComplete()) {
            this->fader.setDirection(sufy::penner::Fader::Direction::OUT);
            this->fader.setComplete(false);
        }
    }

    void SplashState::handleEvents(const sf::Event &event) {
        switch (event.type) {
            case sf::Event::Closed:
                this->machine.quit();
                break;
            default:
                break;
        }
    }
}}}
