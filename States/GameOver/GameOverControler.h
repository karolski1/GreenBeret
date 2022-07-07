//
// Created by Karol on 21.06.2020.
//

#ifndef GREENBERET_GAMEOVERCONTROLER_H
#define GREENBERET_GAMEOVERCONTROLER_H

#include "../../Engine/GameStateControler.h"
#include "../../Engine/Board.h"
class GameOverControler: public GameStateController
    {
        sf::Font font;
        sf::Text SFMLText[14];
        sf::RectangleShape rectengle[10];
        std::string text[3] = {"zaczanij gre", "wybierz poziom", "zakoncz gre"};
        std::string nextState;
        int menuChose;
    Board & board;
    sf::Texture SFMLTexture[20];
    sf::Sprite SFMLSprite[20];
    public:
        explicit GameOverControler(Board & b);
        virtual ~GameOverControler();

        virtual std::string getNextState() const;
        virtual void handleEvent ( const sf::Event & event ) ;
        virtual void updateModel() ;
        virtual void draw(sf::RenderWindow & win) ;

        virtual void onEnter(const std::string & data) ;
        virtual std::string onExit() ;
};


#endif //GREENBERET_GAMEOVERCONTROLER_H
