//
// Created by Karol on 21.05.2020.
//

#ifndef GREENBERET_ENEMY_H
#define GREENBERET_ENEMY_H

#include "../Engine/Character.h"
#include "Hero.h"

enum Level
{
    EASY, NORMAL, HARD
};

class Enemy : public Character
{

    Board &board;
    Hero &hero;
    Level level;
    int AmountofCharacters;
    Character character[100];
    Bullet buletEnemy[100];
    int lastAdedEnemy, lasty, speed, counter, distance, buletdistance;
public:
    Enemy(Board &board, Hero &hero);

    void setLevel(Level level);

    void Reset();

    Level getLevel() const;

    void AddEnemy(int x, int y);

    void Update() override;

    int distanceBetween(int idx);

    const Character *getCharacter() const;

    void MoveBulet(int idx);

    void Attack(Direction dir, int idx);

    void Move(int idx);

    int getLastAdedEnemy() const;

    int Buletdistancefromstart(int idx);

    const Bullet *getBuletEnemy() const;
};


#endif //GREENBERET_ENEMY_H
