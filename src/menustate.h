#include "states.h"
#include "game.h"
#include "button.h"
#include <SFML/Graphics.hpp>


class MenuState : public States {

    public:
        MenuState(sf::RenderWindow& window, Game& game);

        void updateState() override;
        void drawState() override;
        void pauseState() override;

    private:
        Game& m_game;
        Button m_startButton, 
               m_quitButton;
        sf::Text m_logo, 
            m_credit,
            m_version;
};  
