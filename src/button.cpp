#include "button.h"

Button::Button(std::string name, sf::Font& font, sf::Vector2f size, sf::Vector2f position, sf::RenderWindow& window) :
    m_buttonBody(size) , m_position(position) , m_buttonText(name,font) , m_buttonState(Default) , m_window(window)
{

    m_buttonBody.setOrigin(size/2.f - sf::Vector2f(1,1));
    m_buttonBody.setPosition(position);

    updateTextPosition();
}

Button::ButtonState Button::getState() {

    return m_buttonState;
}

void Button::setState(Button::ButtonState state) {

    m_buttonState = state; 
}

void Button::setTextSize(unsigned int size) {

    m_buttonText.setCharacterSize(size);
    updateTextPosition();
}

void Button::updateTextPosition() {

    m_buttonText.setOrigin(m_buttonText.getLocalBounds().getSize()/2.f + m_buttonText.getLocalBounds().getPosition() - sf::Vector2f(1,1));
    m_buttonText.setPosition(m_position);
}

void Button::update() {

    m_buttonState = Default;
    m_buttonBody.setOutlineThickness(0);
    m_buttonBody.setFillColor(m_defaultColor);

    if(m_buttonBody.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(m_window)))) {

        m_buttonState = Focused;
        m_buttonBody.setOutlineThickness(5);
        m_buttonBody.setFillColor(m_defaultColor);
    }

    if(m_buttonState == Focused && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        m_buttonState = Pressed;
        m_buttonBody.setOutlineThickness(5);
        m_buttonBody.setFillColor(m_pressedColor);
    }
}

void Button::draw() {

    m_window.draw(m_buttonBody);
    m_window.draw(m_buttonText);
}
