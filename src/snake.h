#pragma once

#include <deque>
#include "level.h"
#include <SFML/Graphics.hpp>

class Snake {

    public:

        Snake(sf::Vector2i position, sf::Vector2i direction, sf::Color color, Level& level);


        int getSnakeSize();
        bool isDead();
        void updateSnake();
        void respawnSnake(sf::Vector2i position, sf::Vector2i direction);
        void setDirection(sf::Vector2i newDirection);
        sf::Vector2i getDirection();

        static const sf::Color m_foodColor;
        static const sf::Color m_emptyColor;

    private:

        void clearHead();

        std::deque<sf::Vector2i> m_snakeBody;
        sf::Vector2i m_direction;
        const sf::Color m_bodyColor;
        bool m_isDead;
        Level& m_level;
};
