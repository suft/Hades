#pragma once

#include <stack>
#include <memory>
#include "State.hpp"

namespace sufy { namespace state {

    template <typename Adapter>
    class StateMachine {
    private:
        std::stack<std::unique_ptr<State<Adapter>>> states;
        bool resume;
        bool running;
    public:
        StateMachine();

        bool isRunning();
        void quit();

        void run(std::unique_ptr<State<Adapter>> state);

        void update(float dt);
        void render();

        void next();
        void last();
    };
}}
