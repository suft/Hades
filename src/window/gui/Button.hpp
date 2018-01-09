#pragma once

#include <string>
#include <functional>
#include "TextView.hpp"
#include "../../graphics/ActionColours.hpp"

namespace sufy { namespace window { namespace gui {

    class Menu;

    typedef std::function<void()> Thunk;

    class Button : public TextView {
    protected:
        sufy::graphics::ActionColours colours;
        Thunk thunk;
        bool selected;
        bool clicked;
        friend class Menu;
    public:
        Button(float position, sf::Text text, sufy::graphics::ActionColours colours, Thunk thunk);

        void select(bool value);
        void click(bool value);

        std::string getName() {
            return text.getString();
        }

        virtual void update(float dt) override;
        virtual void render(sf::RenderTarget& rt) override;
    };
}}}
