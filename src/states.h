#pragma once

#include <SFML/Graphics.hpp>

class States {

    public:

        States(sf::RenderWindow& window);
        virtual ~States();

        virtual void updateState() = 0;
        virtual void drawState() = 0;
        virtual void pauseState() = 0;

    protected:
        sf::RenderWindow& m_window;

};
