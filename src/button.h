#pragma once

#include <SFML/Graphics.hpp>

class Button {

    public:
        enum ButtonState {
        Default, Focused, Pressed
        };

        Button(std::string name, sf::Font& font, sf::Vector2f size, sf::Vector2f position, sf::RenderWindow& window);

        ButtonState getState();
        void setState(ButtonState state);
        void setTextSize(unsigned int size);
        void update();
        void draw();

    protected:
        void updateTextPosition();

    private:
        sf::Text m_buttonText;
        sf::RectangleShape m_buttonBody;
        ButtonState m_buttonState;
        sf::Vector2f m_position;
        sf::RenderWindow& m_window;
        sf::Color m_defaultColor = sf::Color(0,0,255);
        sf::Color m_pressedColor = sf::Color(0,0,100);
};
