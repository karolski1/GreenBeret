//
// Created by Karol on 21.05.2020.
//

#include "Board.h"
#include <iostream>

Board::Board()
{//drobina : 190/230/300/360/370/500/530/570/580/610/650/670
//3000/16=187,5~188col(187)-5000=312,5~313col(312)drabiny -6250=390,625~391col(390)dorga 5440/16=340col(339)konca wys=300/20=15row(14) od gory poczatkowa 380=row(18)
//7900/16=493,75~494col(493) wys 180/20=9=row(8) 11350/16~710col(709)
//normalna droga //780/20=39=col(38)-path
    this->ResetBoard();

    for (int col = 0; col < height; ++col)
    {
        for (int row = 0; row < width; ++row)
        {
            board[row][col].isPath = false;
            board[row][col].isBulet = false;
            board[row][col].isCharacter = false;
            board[38][col].isPath = true;
            board[39][col].isPath = true;
            if (col >= 238 && col <= 390)
            {
                if (col <= 289)
                {
                    if (row > 11 && row < 39)
                        switch (col)
                        {
                            case 190:
                                board[row][col].isPath = true;
                                break;

                            case 237:
                            case 238:
                            case 239:
                            case 240:
                            case 241:
                            case 242:
                            case 243:
                                board[row][col].isPath = true;
                                break;
                            default:
                                board[12][col].isPath = true;
                                break;

                        }
                } else if (col < 338)
                {
                    if (row > 17 && row < 39)
                        switch (col)
                        {
                            case 290:
                            case 291:
                            case 292:
                            case 293:
                            case 294:
                            case 295:
                            case 289:
                            case 296:
                                board[row][col].isPath = true;
                                break;
                            default:
                                board[18][col].isPath = true;
                                break;
                        }
                } else
                {
                    if (row > 13 && row < 39)
                    {
                        switch (col)
                        {
                            case 290:
                            case 291:
                            case 292:
                            case 293:
                            case 294:
                            case 295:
                            case 289:
                            case 296:
                                board[row][col].isPath = true;
                                break;
                            case 338:
                                for (int i = 14; i < 19; ++i)
                                {
                                    board[i][col].isPath = true;
                                }

                                break;
                            case 360:

                                board[row][col].isPath = true;

                                break;
                            case 370:

                                board[row][col].isPath = true;

                                break;
                            default:
                                board[14][col].isPath = true;
                                break;
                        }
                    }
                }

            }
            if (col > 492 && col < 696)
            {
                if (row > 7 && row < 39)
                {
                    switch (col)
                    {
                        case 530:
                        case 527:
                        case 528:
                        case 529:
                        case 526:
                        case 531:
                        case 532:
                        case 533:

                            board[row][col].isPath = true;

                            break;
                        case 588:
                        case 589:
                        case 590:
                        case 591:
                        case 592:
                        case 593:
                        case 594:
                        case 595:

                            board[row][col].isPath = true;

                            break;

                        case 624:
                        case 625:
                        case 626:
                        case 627:
                        case 628:
                        case 629:
                        case 630:
                        case 631:

                            board[row][col].isPath = true;

                            break;

                        default:
                            board[8][col].isPath = true;
                            break;
                    }
                }
            }

        }
    }
}


void Board::display()
{
    for (int col = 0; col < GetBoardHeight(); ++col)
    {
        for (int row = GetBoardWidth() - 1; row >= 0; --row)
        {
            std::cout << GetFieldInfo(row, col);
        }
        std::cout << col << std::endl;

    }

}

char Board::GetFieldInfo(int x, int y)
{


    if (board[x][y].isPath)
        return '#';
    if (board[x][y].isCharacter)
        return 'X';


    return '_';
}


int Board::GetBoardWidth()
{
    return width;
}

int Board::GetBoardHeight()
{
    return height;
}

void Board::SetGameState(GameState state)
{
    State = state;
}

void Board::ResetBoard()
{
    direction = right;
    lastY = 0;
    distance = 0;
    State = START;
    MoveCounter = 0;
}

void Board::MoveCharacter(int x, int y)
{

    if (x < 0 || x > 45 || y > 1000 || y < 0)
        return;
    if (getState() == RUNNING)
    {
        if (direction == right)
        {
            if (getMoveCounter() < 800)
            {
                if (distance == 50 && lastY < y)
                {
                    ++MoveCounter;
                } else
                {
                    if (distance < 50)
                        ++distance;
                }
            } else if (distance < 97)
                ++distance;
        }
        if (direction == left)
        {
            if (distance > 0)
                --distance;
        }
        board[x][y].isCharacter = true;
        lastY = y;
    }
}

void Board::RemoveCharacter(int x, int y)
{
    board[x][y].isCharacter = false;
}

Direction Board::getDirection() const
{
    return direction;
}

int Board::getMoveCounter() const
{
    return MoveCounter;
}

void Board::swapDirection(int x)
{
    switch (x)
    {
        case 0:
            direction = up;
            break;
        case 1:
            direction = down;
            break;
        case 2:
            direction = left;
            break;
        case 3:
            direction = right;
            break;
        default:
            break;
    }
}

int Board::getDistance() const
{
    return distance;
}

GameState Board::getState() const
{
    if (State == START)
        return START;
    if (State == GAMELOSE)
        return GAMELOSE;
    if (State == GAMEWIN)
        return GAMEWIN;
    if (State == RUNNING)
        return RUNNING;
}




