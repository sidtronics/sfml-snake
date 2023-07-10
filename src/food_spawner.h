#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "level.h"

class FoodSpawner {

    public:
        FoodSpawner(int count, Level& level);

        void updateFood();

    private:

        sf::Vector2i spawnFood();

        std::vector<sf::Vector2i> m_food;
        Level& m_level;
};
