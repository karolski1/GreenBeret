//
// Created by Karol on 21.05.2020.
//

#ifndef GREENBERET_HERO_H
#define GREENBERET_HERO_H
#include "../Engine/Character.h"
#include "../Engine/Board.h"




class Hero:public Character
{
    int positionX, positionY,buletdistance;
    Board & board;
    Bullet bulet[100];

public:
    explicit Hero(Board & b);
    void Move(Direction direction, bool isBoardMove);
    int GetPositionX () const override;
    int GetPositionY() const override;
    void MoveBulet(int idx);
    const Bullet *getBulet() const;
    void Attack(Direction dir);
    void reset();
    int Buletdistancefromstart(int idx, bool haveHit);
    void Update() override;

};
#endif //GREENBERET_HERO_H
