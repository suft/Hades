#pragma once

#include <SFML/Graphics.hpp>
#include "../constant/Flags.hpp"
#include "../state/State.hpp"
#include "../state/StateMachine.hpp"
#include "states/SplashState.hpp"

namespace sufy { namespace game {

    typedef sufy::state::StateMachine<sf::RenderWindow> GameStateMachine;

    class Application {
    private:
        GameStateMachine machine;
        sf::RenderWindow window;
    public:
        Application() = default;
        void run();
    };
}}
