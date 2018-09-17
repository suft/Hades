#pragma once

#include "Object.hpp"

namespace sufy { namespace objects {

    class Destoyable : public Object {
    public:
        virtual void destroy(Object player);
    };

}}
