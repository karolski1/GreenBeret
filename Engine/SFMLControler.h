//
// Created by Karol on 29.05.2020.
//

#ifndef GREENBERET_SFMLCONTROLER_H
#define GREENBERET_SFMLCONTROLER_H

#include "../Characters/Hero.h"
#include "../Characters/Enemy.h"
#include "Board.h"
#include "SFMLView.h"
#include "Character.h"
class SFMLControler
{
    Board &board;
    Hero &hero;
    Enemy &enemy;
    SFMLView &view;
    Character &character;
    bool counter=false;

public:
    SFMLControler(Board &board, Hero &hero, Enemy &enemy, SFMLView &view, Character &character);
    void showkeybordevent(sf::Event &event);
void GameState();
};


#endif //GREENBERET_SFMLCONTROLER_H
