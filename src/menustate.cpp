#include "menustate.h"
#include "gamestate.h"
#include <SFML/Audio.hpp>

MenuState::MenuState(sf::RenderWindow& window, Game& game) :
    States(window), 
    m_game(game),
    m_startButton("Start" , m_game.getFont(), sf::Vector2f(100,30), sf::Vector2f(400.f,450.f*2/4), window),
    m_quitButton("Quit" , m_game.getFont(), sf::Vector2f(100,30), sf::Vector2f(400,450.f*3/4), window),
    m_logo("Snake", m_game.getFont(), 75),
    m_credit("Made by Siddhesh Dharme", m_game.getFont(), 12),
    m_version("v1.0.0", m_game.getFont(), 12) {


    m_logo.setOrigin(m_logo.getLocalBounds().getSize()/2.f + m_logo.getLocalBounds().getPosition() - sf::Vector2f(1,1));
    m_logo.setPosition({400,100});
    m_logo.setFillColor(sf::Color::Blue);
    m_logo.setStyle(sf::Text::Bold);
    m_logo.setOutlineThickness(3);
    m_logo.setOutlineColor(sf::Color::White);

    m_credit.setPosition(sf::Vector2f(800,450) - m_credit.getLocalBounds().getSize() + m_credit.getLocalBounds().getPosition() - sf::Vector2f(5,5));
    m_version.setPosition({5, 450 - 5 - m_version.getLocalBounds().getSize().y - m_version.getLocalBounds().getPosition().y});

    m_startButton.setTextSize(20);
    m_quitButton.setTextSize(20);

    }

void MenuState::updateState() {
    
    m_startButton.update();
    if(m_startButton.getState() == Button::Pressed) {
        m_game.pushState(std::make_unique<GameState>(m_window, m_game));
    }

    m_quitButton.update();
    if(m_quitButton.getState() == Button::Pressed) {
        m_window.close();
    }
}

void MenuState::drawState() {

    m_startButton.draw();
    m_quitButton.draw();
    m_window.draw(m_logo);
    m_window.draw(m_credit);
    m_window.draw(m_version);
}

void MenuState::pauseState() {

}
