#pragma once

#include "Object.hpp"

namespace sufy { namespace objects {

    class Collectable : public Object {
    public:
        virtual void collect(Object player);
    };

}}
