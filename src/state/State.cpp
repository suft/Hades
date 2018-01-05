#include "State.hpp"

namespace sufy { namespace state {

    template <typename Adapter>
    State<Adapter>::State(StateMachine<Adapter> &machine, Adapter &adapter, bool replace): machine(machine), adapter(adapter), replace(replace) {}

    template <typename Adapter>
    bool State<Adapter>::isReplacing() const {
        return this->replace;
    }

    template <typename Adapter>
    std::unique_ptr<State<Adapter>> State<Adapter>::next() {
        return std::move(this->after);
    }
}}
