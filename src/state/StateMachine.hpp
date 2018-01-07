#pragma once

#include <stack>
#include <memory>
#include "State.hpp"

namespace sufy { namespace state {

    template <typename Adapter>
    class State;

    template <typename Adapter>
    class StateMachine {
    private:
        std::stack<std::unique_ptr<State<Adapter>>> states;
        bool resume;
        bool running;
    public:
        StateMachine(): resume(false), running(false) {}

        bool isRunning() {
            return this->running;
        }

        void quit() {
            this->running = false;
        }

        void run(std::unique_ptr<State<Adapter>> state) {
            this->running = true;
            this->states.push(std::move(state));
        }

        void update(float dt) {
            this->states.top()->update(dt);
        }

        void render() {
            this->states.top()->render();
        }

        void next() {
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

        void last() {
            this->resume = true;
        }
    };
}}
