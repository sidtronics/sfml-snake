#include "snake.h"


Snake::Snake(sf::Vector2i position, sf::Vector2i direction, sf::Color color, Level& level)
    : m_direction(direction) , m_bodyColor(color), m_level(level), m_isDead(false) {

    m_snakeBody.push_front(position - direction);
    m_level.writeAt(m_snakeBody.front(), m_bodyColor);

    m_snakeBody.push_front(position);
    m_level.writeAt(m_snakeBody.front(), m_bodyColor);
}

void Snake::respawnSnake(sf::Vector2i position, sf::Vector2i direction) {

    m_direction = direction;
    m_snakeBody.push_front(position - direction);
    m_level.writeAt(m_snakeBody.front(), m_bodyColor);

    m_snakeBody.push_front(position);
    m_level.writeAt(m_snakeBody.front(), m_bodyColor);
    m_isDead = false;
}

int Snake::getSnakeSize() {

    return m_snakeBody.size();
}

bool Snake::isDead() {

    return m_isDead;
}

void Snake::updateSnake() {
    
    if(!m_isDead) {

        sf::Color nextpos = m_level.readAt(m_snakeBody.front() + m_direction); 

        if(nextpos == m_emptyColor) {
        
            m_snakeBody.push_front(m_snakeBody.front() + m_direction);
            m_level.writeAt(m_snakeBody.front(), m_bodyColor);

            m_level.writeAt(m_snakeBody.back(), m_emptyColor);
            m_snakeBody.pop_back();
        }

        else if(nextpos == m_foodColor) {

            m_snakeBody.push_front(m_snakeBody.front() + m_direction);
            m_level.writeAt(m_snakeBody.front(), m_bodyColor);
        }

        else {
            m_isDead = true;
        }
    }

    else {
        clearHead();
    }
}

void Snake::clearHead() {

    if(m_snakeBody.size() != 0) {

        m_level.writeAt(m_snakeBody.front(), m_emptyColor);
        m_snakeBody.pop_front();
    }
}

void Snake::setDirection(sf::Vector2i newDirection) {

    m_direction = newDirection;
}

sf::Vector2i Snake::getDirection() {

    return m_direction;
}
