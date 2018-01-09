#pragma once

#include <memory>
#include <vector>
#include <SFML/Window/Event.hpp>
#include "View.hpp"
#include "Button.hpp"

namespace sufy { namespace window { namespace gui {

    class Menu {
    private:
        std::vector<std::shared_ptr<View>> views;
        std::vector<std::shared_ptr<Button>> buttons;
        std::vector<std::shared_ptr<Button>>::iterator selector;
    public:
        Menu() = default;

        void finalize();
        void handleInput(const sf::Event& event);
        void add(std::shared_ptr<View> view);

        void update(float dt);
        void render(sf::RenderTarget& rt);
    private:
        bool up(const sf::Event& event);
        bool down(const sf::Event& event);
        bool click(const sf::Event& event);
    };
}}}
