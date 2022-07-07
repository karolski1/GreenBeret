//
// Created by Karol on 21.05.2020.
//

#ifndef GREENBERET_CHARACTER_H
#define GREENBERET_CHARACTER_H

#include "Board.h"
#include <vector>
#include <iostream>

struct Bullet
{
    Direction direction;
    int PositionX,PositionY;
    bool isBullet;
};

class Character
{
    Direction direction;
    int positionX, positionY, life ;

public:
    Character();

void setLife(int Life);

    void setPositionX(int PositionX);

    void setPositionY(int PositionY);

    Direction getDirection() const;

    virtual void Update();

    bool IsAlive() const;

    int GetLife() const;

    bool IsAttacked(int Xbullet,int Ybullet,int targetX,int targetY);

    virtual int GetPositionX() const;

    virtual int GetPositionY() const;
};





#endif //GREENBERET_CHARACTER_H
