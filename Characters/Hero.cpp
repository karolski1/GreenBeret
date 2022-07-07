//
// Created by Karol on 21.05.2020.
//

#include "Hero.h"
#include "iostream"

Hero::Hero(Board &b) : board(b)
{
    this->reset();
}

void Hero::Move(Direction direction, bool isBoardMove)
{
    if (board.getState() == RUNNING)
    {
        board.RemoveCharacter(GetPositionX(), GetPositionY());
        switch (board.getDirection())
        {
            case up:
                if (board.GetFieldInfo(GetPositionX() - 1, GetPositionY()) == '#')
                    --positionX;
                break;
            case down:
                if (board.GetFieldInfo(GetPositionX() + 1, GetPositionY()) == '#')
                    ++positionX;
                break;
            case left:
                if (board.GetFieldInfo(GetPositionX(), GetPositionY() - 1) == '#')
                    if (board.getDistance() > 0)
                        --positionY;
                break;
            case right:
            {
                int i = 0;
                if (board.GetFieldInfo(GetPositionX(), GetPositionY() + 1) == '#')
                {
                    if (positionY < 897)
                        ++positionY;
                } else
                {
                    if (GetPositionY() != 338)
                        while (board.GetFieldInfo(GetPositionX() + i, GetPositionY() + 1) != '#')
                            ++i;
                    positionX = GetPositionX() + i;
                }
                break;
            }
            default:
                break;

        }
        board.MoveCharacter(GetPositionX(), GetPositionY());
    }
}

int Hero::GetPositionX() const
{
    return positionX;
}

int Hero::GetPositionY() const
{
    return positionY;
}

void Hero::MoveBulet(int idx)
{
    if (idx > 99 || idx < 0)
        return;
    if (bulet[idx].isBullet)
    {
        if (Buletdistancefromstart(idx, false) > 50)
        {

            bulet[idx].isBullet = false;
        }

        if (bulet[idx].direction == right)
            bulet[idx].PositionY += 1;
        if (bulet[idx].direction == left)
            bulet[idx].PositionY -= 1;
    }
}

void Hero::Attack(Direction dir)
{
    for (int i = 0; i < 100; ++i)
    {
        if (!bulet[i].isBullet)
        {
            bulet[i].PositionX = GetPositionX();
            bulet[i].PositionX;
            bulet[i].PositionY = GetPositionY();
            bulet[i].direction = dir;
            bulet[i].isBullet = true;
            return;
        }
    }
}

const Bullet *Hero::getBulet() const
{
    return bulet;
}

int Hero::Buletdistancefromstart(int idx, bool haveHit)
{
    if (!haveHit)
    {
        if (bulet[idx].PositionY > GetPositionY())
            buletdistance = bulet[idx].PositionY - GetPositionY();
        else
            buletdistance = GetPositionY() - bulet[idx].PositionY;
        return buletdistance;
    } else
    {
        bulet[idx].isBullet = false;
    }
}

void Hero::Update()
{

    if (IsAlive())
        for (int i = 0; i < 100; ++i)
            MoveBulet(i);
}

void Hero::reset()
{
    positionX = 38;
    positionY = 0;
    setLife(100);
}
