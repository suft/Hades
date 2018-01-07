#pragma once

#include <SFML/Graphics/Text.hpp>
#include "View.hpp"

namespace sufy { namespace window { namespace gui {

    class TextView : public View {
        sf::Text text;
    public:
        TextView() = default;
        TextView(float position, sf::Text text);

        void update(float dt) override;
        void render(sf::RenderTarget& rt);
    };
}}}
