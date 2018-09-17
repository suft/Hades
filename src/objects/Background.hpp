#pragma once

#include "Object.hpp"

namespace sufy { namespace objects {

    class Background : public Object {
    public:
        Background() = default;
        Background(float x, float y, float size, int id, sf::Texture tex);
    };

}}
