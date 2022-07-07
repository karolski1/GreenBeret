//
// Created by Karol on 21.05.2020.
//

#ifndef GREENBERET_BOARD_H
#define GREENBERET_BOARD_H
enum GameState
{
    RUNNING,LEVEL,QUIT,START,PAUZA,GAMELOSE,GAMEWIN
};
struct Field
{
bool isBulet,isCharacter,isPath;
};
enum Direction
{
    up, down, left, right
};
class Board
{
    Direction direction;
    Field board[45][1000];
int distance,width=45,height=1000,lastY;
    int MoveCounter;
    GameState State;
public:


    Board();
    int getMoveCounter() const;

    GameState getState() const;

    void display();
void MoveCharacter(int x,int y );
void RemoveCharacter(int x, int y);

char GetFieldInfo(int x,int y);

    Direction getDirection() const;
    int getDistance() const;
    int GetBoardWidth();
    int GetBoardHeight();
    void SetGameState(GameState state);
    void ResetBoard();
    void swapDirection(int x);
};


#endif //GREENBERET_BOARD_H
