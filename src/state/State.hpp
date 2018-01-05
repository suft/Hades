#pragma once

#include <memory>

namespace sufy { namespace state {
    template <typename Adapter>
    class StateMachine;

    template <typename Adapter>
    class State {
    protected:
        std::unique_ptr<State<Adapter>> after;
        StateMachine<Adapter>& machine;
        Adapter& adapter;
        bool replace;
    public:
        State(StateMachine<Adapter>& machine, Adapter& adapter, bool replace);
        virtual ~State() = default;

        State(const State&) = delete;
        State<Adapter>& operator=(const State&) = delete;

        std::unique_ptr<State> next();
        bool isReplacing() const;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void update(float dt) = 0;
        virtual void render() = 0;
    };
}}
