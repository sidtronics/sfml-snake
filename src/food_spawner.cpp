#include <cstdlib>
#include <chrono>
#include "food_spawner.h"
#include "snake.h"

FoodSpawner::FoodSpawner(int count, Level& level)
    : m_level(level) {

    std::srand(std::chrono::steady_clock::now().time_since_epoch().count());

    for(int i = 0; i < count; ++i) {
    
        m_food.push_back(spawnFood());
    }
}

void FoodSpawner::updateFood() {

    for(auto it = m_food.begin(); it != m_food.end(); ++it) {
        
        if(m_level.readAt(*it) != Snake::m_foodColor)
            *it = spawnFood();
    }
}

sf::Vector2i FoodSpawner::spawnFood() {

    sf::Vector2i food_pos;

    do {
        food_pos.x = std::rand() % 50;//m_level.getDimensions().x;
        food_pos.y = std::rand() % 50;//m_level.getDimensions().y;
    } while(m_level.readAt(food_pos) != Snake::m_emptyColor);

    m_level.writeAt(food_pos, Snake::m_foodColor);
    return food_pos;
}
