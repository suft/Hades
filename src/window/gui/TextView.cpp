#include "TextView.hpp"

namespace sufy { namespace window { namespace gui {

    TextView::TextView(float position, sf::Text text): View(position, text.getCharacterSize()), text(text) {
        sf::FloatRect size = this->text.getLocalBounds();
        this->text.setPosition(
                sufy::constant::CENTER.x - size.width/2,
                position - height/1.5f
        );
    }

    void TextView::update(float dt) {}

    void TextView::render(sf::RenderTarget &rt) {
        View::render(rt);
        rt.draw(this->text);
    }
}}}
