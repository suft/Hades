#include "Menu.hpp"

namespace sufy { namespace window { namespace gui {

    void Menu::add(std::shared_ptr<View> view) {
        this->views.emplace_back(view);
        auto button = std::dynamic_pointer_cast<Button>(view);
        if (button) this->buttons.emplace_back(button);
    }

    void Menu::finalize() {
        this->selector = this->buttons.begin();
    }

    void Menu::handleInput(const sf::Event& event) {
        if (this->up(event)) {
            (*this->selector)->select(false);
            (*this->selector)->click(false);
            this->selector--;
            if (this->selector == this->buttons.begin() - 1) this->selector = this->buttons.end() - 1;
        } else if (this->down(event)) {
            (*this->selector)->select(false);
            (*this->selector)->click(false);
            this->selector++;
            if (this->selector == this->buttons.end()) this->selector = this->buttons.begin();
        } else if (this->click(event)) {
            (*this->selector)->click(true);
        }
    }

    bool Menu::up(const sf::Event& event) {
        return (
            (event.key.code == sf::Keyboard::Up) or
            (sf::Joystick::isConnected(0) and event.joystickButton.button == sufy::constant::LB_BUTTON)
        );
    }

    bool Menu::down(const sf::Event& event) {
        return (
            (event.key.code == sf::Keyboard::Down) or
            (sf::Joystick::isConnected(0) and event.joystickButton.button == sufy::constant::RB_BUTTON)
        );
    }

    bool Menu::click(const sf::Event &event) {
        return (
            (event.key.code == sf::Keyboard::Space) or
            (sf::Joystick::isConnected(0) and event.joystickButton.button == sufy::constant::A_BUTTON)
        );
    }

    void Menu::update(float dt) {
        (*this->selector)->select(true);
        for (auto view : this->views) {
            view->update(dt);
        }
    }

    void Menu::render(sf::RenderTarget& rt) {
        for (auto view : this->views) {
            view->render(rt);
        }
    }
}}}
