//
// Created by Karol on 21.05.2020.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Board &board, Hero &hero) : board(board), hero(hero)
{
    this->Reset();

}

void Enemy::AddEnemy(int x, int y)
{
    if (lastAdedEnemy < AmountofCharacters)
    {
        while (board.GetFieldInfo(x, y) != '#')
        {
            ++x;
            if (x > 38)
                x = 0;
        }
        character[lastAdedEnemy].setPositionX(x);
        character[lastAdedEnemy].setPositionY(y);

        character[lastAdedEnemy].setLife(1);
        ++lastAdedEnemy;
        if (board.getDistance() > 50)
            while (lastAdedEnemy < AmountofCharacters)
            {
                if (lastAdedEnemy % 2 == 0)
                    AddEnemy(38, lastAdedEnemy * 8);
                else
                    AddEnemy(38, lastAdedEnemy * 11);

            }
    }
}

void Enemy::Update()
{
    if (level == EASY)
        AmountofCharacters = 40;
    if (level == NORMAL)
        AmountofCharacters = 70;
    if (level == HARD)
        AmountofCharacters = 100;
    if (hero.GetPositionY() % 50 == 0 && lasty != hero.GetPositionY() || board.getDistance() > 50)
    {
        lasty = hero.GetPositionY();
        AddEnemy(hero.GetPositionX(), hero.GetPositionY() - 50);
        AddEnemy(hero.GetPositionX(), hero.GetPositionY() + 150);
    }
    for (int i = 0; i < 100; ++i)
    {
        if (hero.IsAttacked(getBuletEnemy()[i].PositionX, getBuletEnemy()[i].PositionY,
                            hero.GetPositionX(), hero.GetPositionY()) && buletEnemy[i].isBullet)
        {
            buletEnemy[i].isBullet = false;
            hero.setLife(hero.GetLife() - 1);
        }
        for (int j = 0; j < 100; ++j)
        {
            if (character[j].IsAlive())
                if (IsAttacked(hero.getBulet()[i].PositionX, hero.getBulet()[i].PositionY, character[j].GetPositionX(),
                               character[j].GetPositionY()) && hero.getBulet()[i].isBullet)
                {
                    character[j].setLife(character[j].GetLife() - 1);
                    if (character[j].GetLife() <= 0)
                        hero.Buletdistancefromstart(i, true);
                }
        }
        if (counter % 5 == 0)
            MoveBulet(i);
        if (counter % 15 == 0)
        {
            counter = 0;
            if (character[i].IsAlive())
            {
                Move(i);
            }
        }
        if (speed % 165 == 0)
        {
            speed = 0;
            for (int j = 0; j < 100; ++j)
            {
                if (character[j].IsAlive())
                {
                    if (distanceBetween(j) < 50)
                        Attack(character[j].getDirection(), j);
                }
            }
        }
    }
    ++counter;
    ++speed;
}

const Character *Enemy::getCharacter() const
{
    return character;
}

int Enemy::distanceBetween(int idx)
{
    if (hero.GetPositionY() > character[idx].GetPositionY())
        distance = (hero.GetPositionY() - character[idx].GetPositionY());
    else
        distance = (character[idx].GetPositionY() - hero.GetPositionY());
    return distance;
}

void Enemy::MoveBulet(int idx)
{
    if (idx > 99 || idx < 0)
        return;
    if (buletEnemy[idx].isBullet)
    {
        if (buletEnemy[idx].direction == right)
            buletEnemy[idx].PositionY += 1;
        if (buletEnemy[idx].direction == left)
            buletEnemy[idx].PositionY -= 1;
        if (Buletdistancefromstart(idx) > 50)
            buletEnemy[idx].isBullet = false;
    }
}

void Enemy::Attack(Direction dir, int idx)
{
    for (int i = 0; i < 100; ++i)
    {
        if (!buletEnemy[i].isBullet)
        {
            buletEnemy[i].PositionX = character[idx].GetPositionX();
            buletEnemy[i].PositionY = character[idx].GetPositionY();
            buletEnemy[i].direction = dir;
            buletEnemy[i].isBullet = true;
            return;
        }
    }
}

void Enemy::Move(int idx)
{
    int tempX = character[idx].GetPositionX();
    if (character[idx].GetPositionY() + 2 < hero.GetPositionY())
    {
        while (board.GetFieldInfo(tempX, character[idx].GetPositionY() + 1) != '#')
        {
            --tempX;
            if (tempX == 0)
                tempX = 45;
        }
        character[idx].setPositionX(tempX);
        character[idx].setPositionY(character[idx].GetPositionY() + 1);
    }
    if (character[idx].GetPositionY() - 2 > hero.GetPositionY())
    {
        while (board.GetFieldInfo(tempX, character[idx].GetPositionY() + 1) != '#')
        {
            ++tempX;
            if (tempX == 45)
                tempX = 0;
        }
        character[idx].setPositionX(tempX);
        character[idx].setPositionY(character[idx].GetPositionY() - 1);
    }
}

const Bullet *Enemy::getBuletEnemy() const
{
    return buletEnemy;
}

int Enemy::Buletdistancefromstart(int idx)
{
    if (buletEnemy[idx].PositionY > character[idx].GetPositionY())
        buletdistance = buletEnemy[idx].PositionY - character[idx].GetPositionY();
    else
        buletdistance = character[idx].GetPositionY() - buletEnemy[idx].PositionY;
    return buletdistance;
}

int Enemy::getLastAdedEnemy() const
{
    return lastAdedEnemy;
}

void Enemy::setLevel(Level level)
{
    Enemy::level = level;
}

Level Enemy::getLevel() const
{
    return level;
}

void Enemy::Reset()
{
    for (int i = 0; i < 100; ++i)
    {
        character[i].IsAlive() == false;
        character[i].setLife(0);
    }
    lastAdedEnemy = 0;
    counter = 0;
    speed = 0;
    lasty = hero.GetPositionY();
    Update();
}





