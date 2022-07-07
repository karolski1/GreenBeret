//
// Created by Karol on 20.06.2020.
//

#include "LevelOptionsControler.h"
#include <iostream>
#include <cstring>

LevelOptionsControler::LevelOptionsControler(Enemy &e):GameStateController("LEVEL"), enemy(e)
{
    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    nextState = this->getStateID();
    rectengle[0].setFillColor(sf::Color::Blue);
    rectengle[0].setSize(sf::Vector2f(350,100));
    rectengle[0].setOutlineColor(sf::Color::Black);
    rectengle[0].setOutlineThickness(15);
    rectengle[1].setFillColor(sf::Color::Blue);
    rectengle[1].setSize(sf::Vector2f(350,100));
    rectengle[1].setOutlineColor(sf::Color::Black);
    rectengle[1].setOutlineThickness(15);
    rectengle[2].setFillColor(sf::Color::Blue);
    rectengle[2].setSize(sf::Vector2f(350,100));
    rectengle[2].setOutlineColor(sf::Color::Black);
    rectengle[2].setOutlineThickness(15);
    for (int n = 0; n <3 ; ++n)
    {
        SFMLText[n].setString(levelText[n]);
        SFMLText[n].setFillColor(sf::Color::Black);
        SFMLText[n].setPosition(rectengle[n].getPosition().x+50,rectengle[n].getPosition().y+50);
        SFMLText[n].setFont(font);
        SFMLText[n].setCharacterSize(20);
    }

}

LevelOptionsControler::~LevelOptionsControler()
{

}

std::string LevelOptionsControler::getNextState() const
{
    return nextState;
}

void LevelOptionsControler::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    { if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            nextState="START";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            swap(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            swap(down);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            MyChoice();
            nextState="START";
        }
    }
}

void LevelOptionsControler::updateModel()
{

}

void LevelOptionsControler::draw(sf::RenderWindow &win)
{
    rectengle[0].setPosition(100,350);
    rectengle[1].setPosition(600,350);
    rectengle[2].setPosition(1100,350);
    for (int n = 0; n < 3; ++n)
    {
        SFMLText[n].setPosition(rectengle[n].getPosition().x + 50, rectengle[n].getPosition().y + 50);
    rectengle[n].setOutlineColor(sf::Color::Blue);
    }
    rectengle[menuChose].setOutlineColor(sf::Color::Yellow);


    for (int i = 0; i <3 ; ++i)
    {
        win.draw(rectengle[i]);
        win.draw(SFMLText[i]);
        }
}

void LevelOptionsControler::onEnter(const std::string &data)
{

    nextState = this->getStateID();
}

std::string LevelOptionsControler::onExit()
{
    return "";
}

void LevelOptionsControler::swap(Direction dir)
{
    if(dir==up)

    {--menuChose;
        if(menuChose<0)
            menuChose=2;
    }
    if(dir==down)
    {
        ++menuChose;
        if(menuChose>2)
            menuChose=0;
    }
}
void LevelOptionsControler::MyChoice()
{
    {
        if (menuChose == 0)
        {
            enemy.setLevel(EASY);

        }else if (menuChose == 1)
            enemy.setLevel(NORMAL);
        else if (menuChose == 2)
            enemy.setLevel(HARD);
    }
}

