#include "StateMachine.hpp"

namespace sufy { namespace state {

    template <typename Adapter>
    StateMachine<Adapter>::StateMachine(): resume(false), running(false) {}

    template <typename Adapter>
    void StateMachine<Adapter>::run(std::unique_ptr<State<Adapter>> state) {
        this->running = true;
        this->states.push(std::move(state));
    }

    template <typename Adapter>
    bool StateMachine<Adapter>::isRunning() {
        return this->running;
    }

    template <typename Adapter>
    void StateMachine<Adapter>::quit() {
        this->running = false;
    }

    template <typename Adapter>
    void StateMachine<Adapter>::next() {
        if (this->resume) {
            if (!this->states.empty()) this->states.pop();
            if (!this->states.empty()) this->states.top()->resume();
            this->resume = false;
        }

        if (!this->states.empty()) {
            std::unique_ptr<State<Adapter>> state = this->states.top()->next();
            if (state) {
                if (state->isReplacing()) this->states.pop();
                else this->states.top()->pause();
                this->states.push(std::move(state));
            }
        }
    }

    template <typename Adapter>
    void StateMachine<Adapter>::last() {
        this->resume = true;
    }

    template <typename Adapter>
    void StateMachine<Adapter>::update(float dt) {
        this->states.top()->update(dt);
    }

    template <typename Adapter>
    void StateMachine<Adapter>::render() {
        this->states.top()->render();
    }

}}
