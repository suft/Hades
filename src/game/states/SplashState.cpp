#include "SplashState.hpp"

namespace sufy { namespace game { namespace states {

    SplashState::SplashState(sufy::state::StateMachine<sf::RenderWindow> &machine, sf::RenderWindow &adapter, bool replace): State<sf::RenderWindow>(machine, adapter, replace) {
        this->logo = sf::Sprite(*sufy::utils::Codex::AcquireTexture("Logo.png"));
        auto local = this->logo.getLocalBounds();
        this->logo.setScale({960 / local.width, 438 / local.height});
        auto global = this->logo.getGlobalBounds();
        this->logo.setPosition({global.width/2, global.height/2 + 100});
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
            this->after = std::unique_ptr<sufy::game::states::MenuState>(new sufy::game::states::MenuState(this->machine, this->adapter, true));
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
