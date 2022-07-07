//
// Created by Karol on 21.05.2020.
//

#ifndef GREENBERET_SFMLVIEW_H
#define GREENBERET_SFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "../Characters/Hero.h"
#include "../Characters/Enemy.h"
#include "Board.h"


class SFMLView: public  sf::Drawable
{
    sf::Font font;

    sf::Text SFMLText[14];
    sf::RectangleShape rectengle[10];

    Enemy & enemy;
    sf::CircleShape bullet[100],bullet2[100];
Hero & hero;
    sf::Texture SFMLTexture[20];
    sf::Sprite SFMLSprite[20];
    sf::Sprite SFMLEnemy[50];
    sf::Sprite SFMLEnemy2[50];
Board & board;
Character & character;
GameState state;
Level level;
int i=1,j=7,k=0,s=13,g=0,w,h,lastY=0,lastdistance=0,lastX,menuChose,LevelChose,LastLevelChose;
public:
    SFMLView(Hero &hero,Enemy &enemy, Board &board,Character & charakter);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void Update();
    void Reset();
    void SwapState(int i);
void swap(Direction dir);
};


#endif //GREENBERET_SFMLVIEW_H
