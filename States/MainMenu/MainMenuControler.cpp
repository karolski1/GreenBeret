//
// Created by Karol on 20.06.2020.
//

#include "MainMenuControler.h"
#include <iostream>
#include <cstring>


MainMenuControler::MainMenuControler(Enemy &e, Board &b) : GameStateController("START"), enemy(e), board(b)
{
    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    nextState = this->getStateID();
    SFMLTexture.loadFromFile("../Images/Menu.png");
    SFMLSprite[3].setTexture(SFMLTexture);
    SFMLSprite[4].setTexture(SFMLTexture);
    SFMLSprite[3].setPosition(0, 0);
    SFMLSprite[4].setPosition(-1598, 0);
    for (int m = 0; m < 3; ++m)
    {
        if (m == 0)
        {
            rectengle[m].setPosition(600, 100);
            SFMLText[m].setPosition(700, 130);
        } else
        {
            rectengle[m].setPosition(rectengle[m - 1].getPosition() + sf::Vector2f(0, 250));
            SFMLText[m].setPosition(SFMLText[m - 1].getPosition() + sf::Vector2f(0, 250));
        }
        rectengle[m].setSize(sf::Vector2f(500, 150));
        rectengle[m].setFillColor(sf::Color::Black);
        rectengle[m].setOutlineThickness(15);
        rectengle[m].setOutlineColor(sf::Color::Black);
        rectengle[menuChose].setOutlineColor(sf::Color::Yellow);

        SFMLText[m].setFont(font);
        SFMLText[m].setCharacterSize(20);
        SFMLText[m].setString(text[m]);
        SFMLText[m].setFillColor(sf::Color::White);
    }

    if (!music.openFromFile("../Music/ISeeRed.ogg"))
        std::cerr << "Blad Otworzenia pliku";

    music.setVolume(100);
    SFMLText[3].setCharacterSize(20);
    SFMLText[3].setFont(font);
    SFMLText[3].setFillColor(sf::Color::White);
    music.play();

}

MainMenuControler::~MainMenuControler()
{

}

std::string MainMenuControler::getNextState() const
{
    return nextState;
}

void MainMenuControler::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            swap(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            swap(down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            Mychoice();

    }
}

void MainMenuControler::updateModel()
{
    music.setLoop(true);
    for (int m = 0; m < 3; ++m)
        rectengle[m].setOutlineColor(sf::Color::Black);
    rectengle[menuChose].setOutlineColor(sf::Color::Yellow);

    SFMLSprite[3].move(0.2, 0);
    SFMLSprite[4].move(0.2, 0);

    if (SFMLSprite[3].getPosition().x > 1600)
    {
        SFMLSprite[3].setPosition(0, 0);
        SFMLSprite[4].setPosition(-1598, 0);
    }
}

void MainMenuControler::draw(sf::RenderWindow &win)
{


    if (closeAplication == true)
        win.close();


    SFMLText[3].setPosition(rectengle[1].getPosition().x + 100, rectengle[1].getPosition().y + 70);

    //std::string x;
    switch (enemy.getLevel())
    {
        case 0:
            SFMLText[3].setString("Obecny Poziom\nEasy");
            break;
        case 1:
            SFMLText[3].setString("Obecny Poziom\nNormal");
            break;
        case 2:
            SFMLText[3].setString("Obecny Poziom\nHard");
            break;
    }
    win.draw(SFMLSprite[4]);
    win.draw(SFMLSprite[3]);
    for (int i = 0; i < 3; ++i)
    {
        win.draw(rectengle[i]);
        win.draw(SFMLText[i]);
    }
    win.draw(SFMLText[3]);
}

void MainMenuControler::onEnter(const std::string &data)
{

    nextState = this->getStateID();
}

std::string MainMenuControler::onExit()
{
    return "";
}

void MainMenuControler::swap(Direction dir)
{
    if (dir == up)
    {
        --menuChose;
        if (menuChose < 0)
            menuChose = 2;
    }
    if (dir == down)
    {
        ++menuChose;
        if (menuChose > 2)
            menuChose = 0;

    }

}

void MainMenuControler::Mychoice()
{
    if (menuChose == 0)
    {
        board.SetGameState(RUNNING);
        nextState = "RUNNING";
        music.stop();
    } else if (menuChose == 1)
    {
        board.SetGameState(LEVEL);
        nextState = "LEVEL";
    } else if (menuChose == 2)
        closeAplication = true;
}

