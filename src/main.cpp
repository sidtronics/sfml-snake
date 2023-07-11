#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include "game.h"
#include "menustate.h"
#include "snake.h"

extern const char* VERSION = "v1.0.1";

const sf::Color Snake::m_emptyColor(0,0,0);
const sf::Color Snake::m_foodColor(255,0,0);

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800,450), "Snake", sf::Style::Close | sf::Style::Titlebar);
    
    Game game(window);
    game.pushState(std::make_unique<MenuState>(window, game));

    //game loop
    while(window.isOpen()) {

        game.updateEvents();
        game.updateCurrentState();
        game.renderFrame();
    }

    return 0;
}
