#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Level {

    public:
        Level(sf::RenderWindow& window);
        
        void drawLevel();
        //void writeRow(int row, sf::Color color);
        void writeAt(sf::Vector2i coord, sf::Color color);
        sf::Color readAt(sf::Vector2i coord);

    private:
        sf::Vector2i m_position;
        int m_tileLength;
        std::array<sf::RectangleShape, 2500> m_tiles;
        sf::RenderWindow& m_window;
};
