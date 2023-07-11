#include "states.h"
#include "game.h"
#include "snake.h"
#include "level.h"
#include "button.h"
#include "food_spawner.h"
#include <SFML/Graphics.hpp>
#include <chrono>

class GameState : public States {

    public:
        GameState(sf::RenderWindow& window, Game& game);

        void updateState() override;
        void drawState() override;
        void pauseState() override;
        
        struct Controls {
            sf::Keyboard::Key up, down, left, right, pause;
        };

    private:
        Game& m_game;
        Level m_level;
        Snake m_snake;
        FoodSpawner m_foodSpawner;

        Controls m_control;
        bool m_isPaused;

        Button m_menuButton;
        Button m_retryButton;
        sf::Text m_score, 
            m_gameOver,
            m_instructions,
            m_paused;

        std::chrono::steady_clock::time_point m_currentTime, m_lastTime;
        std::chrono::milliseconds m_gameSpeed;
};
