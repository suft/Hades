#include "Button.hpp"

namespace sufy { namespace window { namespace gui {

    Button::Button(float position, sf::Text text, sufy::graphics::ActionColours colours, Thunk thunk): TextView(position, text), colours(colours), thunk(thunk) {
        this->selected = false;
        this->clicked = false;
    }

    void Button::update(float dt) {
        if (this->selected and this->clicked) {
            this->text.setOutlineColor(this->colours.clicked.outline);
            this->text.setFillColor(this->colours.clicked.fill);
            this->thunk();
        } else if (this->selected) {
            this->text.setOutlineColor(this->colours.selected.outline);
            this->text.setFillColor(this->colours.selected.fill);
        } else {
            this->text.setOutlineColor(this->colours.idle.outline);
            this->text.setFillColor(this->colours.idle.fill);
        }
    }

    void Button::render(sf::RenderTarget &rt) {
        TextView::render(rt);
    }

    void Button::select(bool selected) {
        this->selected = selected;
    }

    void Button::click(bool clicked) {
        this->clicked = clicked;
    }
}}}
