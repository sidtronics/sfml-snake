#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>
#include "states.h"


class Game {

    public:
        Game(sf::RenderWindow& window);
 

        void pushState(std::unique_ptr<States> state);
        void popState();
        void updateEvents();
        void updateCurrentState();
        void renderFrame();
        sf::Font& getFont();

    private:
        sf::RenderWindow& m_window;
        sf::Font m_font;
        std::stack<std::unique_ptr<States>> m_states;
};
