#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../constant/Flags.hpp"
#include "../utils/Misc.hpp"

namespace sufy { namespace penner {

    class Fader {
    public:
        enum class Direction {IN, OUT};
    private:
        float duration;
        float current;
        float alpha;
        bool complete;
        sf::RectangleShape overlay;
        sf::Color colour;
        Direction direction;
        sufy::constant::Update fadeUpdate;
        sufy::constant::Render fadeRender;
        sufy::constant::Callback fadeCallback;
    public:
        Fader() = default;
        Fader(Direction direction, float duration, sufy::constant::Update fadeUpdate, sufy::constant::Render fadeRender, sufy::constant::Callback fadeCallback);

        void update(float dt);
        void render(sf::RenderTarget& rt);

        Direction getDirection();
        void setDirection(Direction direction);

        bool isComplete();
        void setComplete(bool complete);
    private:
        float getPercentage();
    };
}}
