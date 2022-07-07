//
// Created by Karol on 21.05.2020.
//
#include "Character.h"
#include <iostream>

Character::Character()
{
    positionX = 38;
    positionY = 0;
    life = 0;
}

bool Character::IsAlive() const
{
    if (GetLife() <= 0)
        return false;
    else
        return true;
}

int Character::GetLife() const
{
    return life;
}

void Character::Update()
{

}

bool Character::IsAttacked(int Xbullet, int Ybulllet, int targetX, int targetY)
{
    if (targetX == Xbullet && targetY == Ybulllet)
        return true;
    else
        return false;
}

int Character::GetPositionX() const
{
    return positionX;
}

int Character::GetPositionY() const
{
    return positionY;
}


void Character::setPositionX(int PositionX)
{
    positionX = PositionX;
}

void Character::setPositionY(int PositionY)
{
    if (positionY > PositionY)
        direction = left;
    if (positionY < PositionY)
        direction = right;
    positionY = PositionY;

}

void Character::setLife(int Life)
{
    life = Life;
}


Direction Character::getDirection() const
{
    return direction;
};








