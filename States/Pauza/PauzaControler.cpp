//
// Created by Karol on 21.06.2020.
//
#include "PauzaControler.h"
#include <iostream>
#include <cstring>
PauzaControler::PauzaControler(Board & b):GameStateController("PAUZA"),board(b)
{
    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    nextState = this->getStateID();

}
PauzaControler::~PauzaControler()
{

}
std::string PauzaControler::getNextState() const
{
    return nextState;
}
void PauzaControler::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            swap();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            swap();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            Mychoice();
    }

}
void PauzaControler::updateModel()
{

}
void PauzaControler::draw(sf::RenderWindow &win)
{
    rectengle[3].setPosition(500,300);
    rectengle[3].setFillColor(sf::Color::Blue);
    rectengle[3].setSize(sf::Vector2f(700,300));
    rectengle[4].setPosition(600,500);
    rectengle[4].setFillColor(sf::Color::White);
    rectengle[4].setSize(sf::Vector2f(200,50));

    rectengle[4].setOutlineThickness(20);
    rectengle[5].setOutlineThickness(20);
    rectengle[5].setPosition(950,500);
    rectengle[5].setFillColor(sf::Color::White);
    rectengle[5].setSize(sf::Vector2f(200,50));
    SFMLText[11].setFont(font);
    SFMLText[11].setCharacterSize(30);
    SFMLText[11].setPosition(rectengle[3].getPosition().x+10,rectengle[3].getPosition().y+10);
    SFMLText[11].setFillColor(sf::Color::Black);
    SFMLText[11].setString(text[0]);
    SFMLText[12].setFont(font);
    SFMLText[12].setCharacterSize(30);
    SFMLText[12].setPosition(rectengle[4].getPosition().x+10,rectengle[4].getPosition().y+10);
    SFMLText[12].setFillColor(sf::Color::Black);
    SFMLText[12].setString(text[1]);
    SFMLText[13].setFont(font);
    SFMLText[13].setCharacterSize(30);
    SFMLText[13].setPosition(rectengle[5].getPosition().x+10,rectengle[5].getPosition().y+10);
    SFMLText[13].setFillColor(sf::Color::Black);
    SFMLText[13].setString(text[2]);
    for (int m = 3; m <6 ; ++m)
    {
        win.draw(rectengle[m]);
        win.draw(SFMLText[m+8]);
    }
}
void PauzaControler::onEnter(const std::string &data)
{

    nextState = this->getStateID();
}
std::string PauzaControler::onExit()
{
    return "";
}

void PauzaControler::swap()
{

            if (rectengle[4].getOutlineColor() == sf::Color::Yellow)
            {rectengle[5].setOutlineColor(sf::Color::Yellow);
                rectengle[4].setOutlineColor(sf::Color::White);
            }else
            {   rectengle[4].setOutlineColor(sf::Color::Yellow);
            rectengle[5].setOutlineColor(sf::Color::White);
}}



void PauzaControler::Mychoice()
{
    if (rectengle[4].getOutlineColor() == sf::Color::Yellow)
    {
        board.SetGameState(GAMELOSE);
        nextState="RUNNING";
    }   else
    {   board.SetGameState(RUNNING);
nextState="RUNNING";
    }}
