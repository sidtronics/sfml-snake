#include "game.h"

Game::Game(sf::RenderWindow& window) :
    m_window(window) {

    m_font.loadFromFile("res/fonts/fira-code.ttf");
}

void Game::pushState(std::unique_ptr<States> state) {

    m_states.push(std::move(state));
}

void Game::popState() {

    m_states.pop();
}

void Game::updateEvents() {

    sf::Event event;
    while(m_window.pollEvent(event)) {

        if(event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::updateCurrentState() {

    m_states.top()->updateState();
}

void Game::renderFrame() {

    m_window.clear();
    m_states.top()->drawState();
    m_window.display();
}

sf::Font& Game::getFont() {

    return m_font;
}
