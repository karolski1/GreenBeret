//
// Created by Karol on 21.06.2020.
//

#include "GameOverControler.h"
#include <iostream>
#include <cstring>

GameOverControler::GameOverControler(Board &b) : GameStateController("GAMEOVER"), board(b)
{
    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    nextState = this->getStateID();
    SFMLTexture[0].loadFromFile("../Images/plansza.png");
    SFMLSprite[0].setTexture(SFMLTexture[0]);
    SFMLSprite[0].setPosition(-12800, 0);
    SFMLText[10].setFont(font);
    SFMLText[10].setCharacterSize(100);
    SFMLText[10].setPosition(500, 300);

    SFMLText[10].setFillColor(sf::Color::Green);
    SFMLText[10].setCharacterSize(100);

}

GameOverControler::~GameOverControler()
{

}

std::string GameOverControler::getNextState() const
{
    return nextState;
}

void GameOverControler::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            nextState = "START";
    }
}

void GameOverControler::updateModel()
{

}

void GameOverControler::draw(sf::RenderWindow &win)
{
    if (board.getState() == GAMEWIN)
    {
        SFMLSprite[0].move(-0.5, 0);
        if (SFMLSprite[0].getPosition().x > -14400)
        {
            SFMLText[10].setString("wygrana");
        } else
        {
            board.ResetBoard();
            nextState = "START";
        }
    } else if (board.getState() == GAMELOSE)
    {

        SFMLSprite[0].setScale(0, 0);
        SFMLText[10].setString("Gra Przegrana");
        board.ResetBoard();
    }
    win.draw(SFMLSprite[0]);
    win.draw(SFMLText[10]);
}

void GameOverControler::onEnter(const std::string &data)
{
    nextState = this->getStateID();
}

std::string GameOverControler::onExit()
{
    return "";
}
