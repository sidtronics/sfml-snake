#include "gamestate.h"
#include <chrono>
#include <string>

GameState::GameState(sf::RenderWindow& window, Game& game) : 
    States(window),
    m_game(game),
    m_snake({24,24}, {0,-1}, sf::Color::Blue, m_level),
    m_level(window), 
    m_foodSpawner(1,m_level),
    m_menuButton("Menu", m_game.getFont(), {100,30}, {55,20}, window),
    m_retryButton("Again?", m_game.getFont(), {100,30}, {400,245}, window),
    m_score("Score: 0", m_game.getFont(), 15),
    m_gameOver("Game Over!", m_game.getFont(), 25),
    m_instructions("Controls: W,A,S,D,ESC", m_game.getFont(),15),
    m_paused("paused", m_game.getFont(), 15),
    m_control({sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::Escape}),
    m_gameSpeed(100),
    m_isPaused(true)
{
    m_menuButton.setTextSize(20);
    m_retryButton.setTextSize(20);

    m_score.setPosition({200,5});

    m_gameOver.setOrigin(m_gameOver.getLocalBounds().getSize()/2.f + m_gameOver.getLocalBounds().getPosition() - sf::Vector2f(1,1));
    m_gameOver.setPosition({400,205});

    m_instructions.setPosition({600 - m_instructions.getLocalBounds().width,5}); 

    m_paused.setPosition({200,425});
    m_paused.setFillColor(sf::Color::Yellow);
    m_paused.setStyle(sf::Text::Italic);

    m_lastTime = std::chrono::steady_clock::now();
}

void GameState::updateState() {
  
    m_currentTime = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point m_lastButtonTime = m_currentTime;

    sf::Vector2i newDirection = {0,0};

    if(m_window.hasFocus()) {

        if(sf::Keyboard::isKeyPressed(m_control.up)) {newDirection = {0,-1};} 
        if(sf::Keyboard::isKeyPressed(m_control.down)) {newDirection = {0,1};}
        if(sf::Keyboard::isKeyPressed(m_control.left)) {newDirection = {-1,0};} 
        if(sf::Keyboard::isKeyPressed(m_control.right)) {newDirection = {1,0};}

        if(sf::Keyboard::isKeyPressed(m_control.pause) && (std::chrono::milliseconds(200) <= m_currentTime - m_lastButtonTime)) {
            m_isPaused = !m_isPaused;
            m_lastButtonTime = m_currentTime;
        }
    }

    if(!m_isPaused) {
        
        bool isUpdated = true; 

        if(isUpdated && newDirection != -m_snake.getDirection() && (newDirection != sf::Vector2i(0,0))) {
            m_snake.setDirection(newDirection);
            isUpdated = false;
        }
        
        if(m_gameSpeed <= m_currentTime - m_lastTime) {
            m_snake.updateSnake();
            m_foodSpawner.updateFood();

            if(!m_snake.isDead()) {
                m_score.setString("Score: " + std::to_string(m_snake.getSnakeSize() - 2));
            }

            m_lastTime = m_currentTime;
            isUpdated = true;
        }

    } 

    else if(newDirection != sf::Vector2i(0,0)) {
        m_isPaused = false;
    }

    if(m_snake.getSnakeSize() == 0) {

        m_retryButton.update();
        if(m_retryButton.getState() == Button::Pressed) {
            m_snake.respawnSnake({24,24}, {0,-1});
            m_score.setString("Score: " + std::to_string(m_snake.getSnakeSize() - 2));
            m_isPaused = true;
        }
    }

    //This section must always be at last or Menu button will cause seg fault.
    m_menuButton.update();
    if(m_menuButton.getState() == Button::Pressed) {
        m_game.popState();
    }
}

void GameState::drawState() {

    m_menuButton.draw();
    m_level.drawLevel();
    m_window.draw(m_score);
    m_window.draw(m_instructions);

    if(m_isPaused) {
        m_window.draw(m_paused);
    }

    if(m_snake.getSnakeSize() == 0) {
        m_retryButton.draw();
        m_window.draw(m_gameOver);
    }
}

void GameState::pauseState() {

    m_isPaused = true;
}
