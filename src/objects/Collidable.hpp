#pragma once

#include "Object.hpp"

namespace sufy { namespace objects {

    class Collidable : public Object {
    public:
        virtual void collide(Object player);
    };

}}
