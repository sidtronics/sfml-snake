#include "level.h"
#include "snake.h"

Level::Level(sf::RenderWindow& window) : 
    m_tileLength(8) , m_position(200,25) , m_window(window) {
    
    sf::Vector2f currentTilePostion(m_position);
    for(int row = 0; row < 50; row++) {

        for(int col = 0; col < 50; col++) {
            
            sf::RectangleShape& currentTile = m_tiles[row*50 + col];
            currentTile.setSize(sf::Vector2f(m_tileLength, m_tileLength));
            currentTile.setPosition(currentTilePostion);

            if(col == 0 || col == 50 - 1){
                currentTile.setFillColor(sf::Color(175,175,175));
            }

            else if(row == 0 || row == 50 - 1) {
                currentTile.setFillColor(sf::Color(175,175,175));
            }

            else {
                currentTile.setFillColor(Snake::m_emptyColor);
            }

            currentTilePostion.x += m_tileLength;
        }

        currentTilePostion.x = m_position.x;
        currentTilePostion.y += m_tileLength;
    }
}

void Level::drawLevel() {

    for(int row = 0; row < 50; row++) {

        for(int col = 0; col < 50; col++) {

            m_window.draw(m_tiles[row*50 + col]);
        }
    }
}

void Level::writeAt(sf::Vector2i coord, sf::Color color) {

    m_tiles[coord.y*50 + coord.x].setFillColor(color);
}

sf::Color Level::readAt(sf::Vector2i coord) {

    return m_tiles[coord.y*50 + coord.x].getFillColor();
}
