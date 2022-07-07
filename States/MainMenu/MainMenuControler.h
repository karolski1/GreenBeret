//
// Created by Karol on 20.06.2020.
//

#ifndef GREENBERET_MAINMENUCONTROLER_H
#define GREENBERET_MAINMENUCONTROLER_H
#include "../../Engine/GameStateControler.h"
#include "../../Characters/Enemy.h"
#include "SFML/Audio.hpp"

class MainMenuControler: public GameStateController
    {
    sf::Font font;

    sf::Text SFMLText[14];
    sf::RectangleShape rectengle[10];
    std::string text[3] = {"zaczanij gre", "wybierz poziom", "zakoncz gre"};
    sf::Texture SFMLTexture;
    sf::Sprite SFMLSprite[5];
    sf::Music music;
        std::string nextState;
        int menuChose=0;
    GameState state;
    Level level;
    Enemy & enemy;
    Board & board;
    bool closeAplication=false;
    public:
         MainMenuControler(Enemy &e,Board & b);
        virtual ~MainMenuControler();

        virtual std::string getNextState() const;
        virtual void handleEvent ( const sf::Event & event ) ;
        virtual void updateModel() ;
        virtual void draw(sf::RenderWindow & win) ;

        virtual void onEnter(const std::string & data) ;
        virtual std::string onExit() ;
    void swap(Direction dir);

void Mychoice();


};



#endif //GREENBERET_MAINMENUCONTROLER_H
