#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include "View.hpp"

namespace sufy { namespace window { namespace gui {

    class Menu;

    class TextView : public View {
    protected:
        sf::Text text;
    public:
        TextView() = default;
        TextView(float position, sf::Text text);

        void update(float dt) override;
        virtual void render(sf::RenderTarget& rt) override;
        friend sufy::window::gui::Menu;
    };
}}}
