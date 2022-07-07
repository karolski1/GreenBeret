//
// Created by Karol on 20.06.2020.
//

#ifndef GREENBERET_GAMECONTROLER_H
#define GREENBERET_GAMECONTROLER_H

#include "../../Engine/GameStateControler.h"
#include "../../Characters/Hero.h"
#include "../../Characters/Enemy.h"
#include "../../Engine/Board.h"
#include "SFML/Audio.hpp"
class GameControler : public GameStateController
    {
    Enemy & enemy;
    Hero & hero;
    Board & board;
    sf::Music music;
    Character & character;
    int w,k,g,j,i,s,lastX,lastY,lastdistance,nextTexture[50],nextTexture2[50],lastEnemyY[100];
    sf::Font font;
    sf::Text SFMLText[14];
    sf::RectangleShape rectengle[10];
    bool isReset= false;
        std::string nextState;
    sf::CircleShape bullet[100],bullet2[100];
    sf::Texture SFMLTexture[20];
    sf::Texture SFMLTexture2[15];
    sf::Sprite SFMLSprite[20];
    sf::Sprite SFMLEnemy[50];
    sf::Sprite SFMLEnemy2[50];
    public:
        GameControler(Hero &hero,Enemy &enemy, Board &board,Character & charakter);
        virtual ~GameControler();

        virtual std::string getNextState() const;
        virtual void handleEvent ( const sf::Event & event ) ;
        virtual void updateModel() ;
        virtual void draw(sf::RenderWindow & win) ;

        virtual void onEnter(const std::string & data) ;
        virtual std::string onExit() ;
        void reset();
        void SwapStateTexture(int idx);
    void SwapStateTexture2(int idx);
    };


#endif //GREENBERET_GAMECONTROLER_H
