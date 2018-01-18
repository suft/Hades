#pragma once

#include <memory>

namespace sufy { namespace state {
    template <typename Adapter>
    class StateMachine;

    enum class StateMode {ADD, REPLACE_TOP, REPLACE_ALL};

    template <typename Adapter>
    class State {
    public:
    protected:
        std::unique_ptr<State<Adapter>> after;
        StateMachine<Adapter>& machine;
        Adapter& adapter;
        StateMode mode;
    public:
        State(StateMachine<Adapter>& machine, Adapter& adapter, StateMode mode): machine(machine), adapter(adapter), mode(mode) {}
        virtual ~State() = default;

        State(const State<Adapter>&) = delete;
        State<Adapter>& operator=(const State<Adapter>&) = delete;

        std::unique_ptr<State<Adapter>> next() {
            return std::move(this->after);
        }

        StateMode getMode() const {
            return this->mode;
        }

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void update(float dt) = 0;
        virtual void render() = 0;
    };
}}
