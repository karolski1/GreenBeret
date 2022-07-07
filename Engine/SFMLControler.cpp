//
// Created by Karol on 29.05.2020.
//

#include "SFMLControler.h"
#include <iostream>

SFMLControler::SFMLControler(Board &board, Hero &hero, Enemy &enemy, SFMLView &view, Character &character) :
        board(board), hero(hero), enemy(enemy), view(view), character(character)
{

}

void SFMLControler::showkeybordevent(sf::Event &event)
{
    if (event.type == sf::Event::MouseMoved)
        return;
    if (board.getState() == GAMELOSE)
    {

        if (event.type == sf::Event::KeyPressed)
        {
            hero.reset();
            enemy.Reset();
            view.Reset();
            board.ResetBoard();
        }
    }
    if (board.getState() == START)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                view.swap(up);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                view.swap(down);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                view.swap(right);
        }
    }

    if (board.getState() == LEVEL)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                board.SetGameState(START);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                view.swap(up);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                view.swap(down);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                view.swap(left);
                if (counter)
                {
                    board.SetGameState(START);
                    counter = false;
                } else
                    counter = true;
            }
        }
    }
    if (board.getState() == PAUZA)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                view.SwapState(0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                view.SwapState(1);
        }
    }
    if (board.getState() == RUNNING)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                board.SetGameState(PAUZA);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                board.swapDirection(0);
                hero.Move(board.getDirection(), true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                board.swapDirection(1);
                hero.Move(board.getDirection(), true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                board.swapDirection(2);
                hero.Move(board.getDirection(), true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                board.swapDirection(3);
                hero.Move(board.getDirection(), true);

            }

        }
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (board.getDirection() == right || board.getDirection() == left)
                    hero.Attack(board.getDirection());
            }
    }
}

void SFMLControler::GameState()
{
    if (board.getState() == RUNNING)
    {
        if (!hero.IsAlive())
        {
            board.SetGameState(GAMELOSE);
            return;
        }
        if (hero.GetPositionY() > 800)
        {
            for (int i = 0; i < 100; ++i)
            {
                if (enemy.getCharacter()[i].IsAlive())
                    return;
            }
            board.SetGameState(GAMEWIN);
        }
    }
}
