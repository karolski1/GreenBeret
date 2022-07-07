//
// Created by Karol on 20.06.2020.
//

#include "GameControler.h"
#include <iostream>
#include <cstring>

GameControler::GameControler(Hero &hero, Enemy &enemy, Board &board, Character &charakter)
        : GameStateController("RUNNING"), hero(hero), enemy(enemy), board(board), character(charakter)
{
    board.SetGameState(RUNNING);
    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!music.openFromFile("../Music/gunshot.wav"))
        std::cerr << "Błąd Otworzenia pliku";
    music.setVolume(100);
    nextState = this->getStateID();
    SFMLTexture[1].loadFromFile("../Images/walk3bochater.png");
    SFMLTexture[2].loadFromFile("../Images/walk5bochater.png");
    SFMLTexture[3].loadFromFile("../Images/walk6bochater.png");
    SFMLTexture[4].loadFromFile("../Images/lewywalk3bochater.png");
    SFMLTexture[5].loadFromFile("../Images/lewywalk5bochater.png");
    SFMLTexture[6].loadFromFile("../Images/lewywalk6bochater.png");
    //przeciwnik1
    SFMLTexture[7].loadFromFile("../Images/bandyta1.png");
    SFMLTexture[8].loadFromFile("../Images/bandyta2.png");
    SFMLTexture[9].loadFromFile("../Images/bandyta3.png");
    SFMLTexture[10].loadFromFile("../Images/Lewybandyta1.png");
    SFMLTexture[11].loadFromFile("../Images/Lewybandyta2.png");
    SFMLTexture[12].loadFromFile("../Images/lewybandyta3.png");
    SFMLTexture2[7].loadFromFile("../Images/char2.png");
    SFMLTexture2[8].loadFromFile("../Images/char3.png");
    SFMLTexture2[9].loadFromFile("../Images/char4.png");
    SFMLTexture2[10].loadFromFile("../Images/lewychar1.png");
    SFMLTexture2[11].loadFromFile("../Images/lewychar2.png");
    SFMLTexture2[12].loadFromFile("../Images/lewychar3.png");
    SFMLTexture[0].loadFromFile("../Images/plansza.png");
    SFMLSprite[1].setTexture(SFMLTexture[1]);
    SFMLSprite[0].setTexture(SFMLTexture[0]);
    reset();
    i = 1;
    SFMLText[6].setString("Lives");
    SFMLText[6].setPosition(0, 0);
    SFMLText[6].setFont(font);
    SFMLText[6].setFillColor(sf::Color::Red);
    SFMLText[6].setCharacterSize(20);
    SFMLText[7].setPosition(60, 0);
    SFMLText[7].setFont(font);
    SFMLText[7].setFillColor(sf::Color::Red);
    SFMLText[7].setCharacterSize(14);
    SFMLText[8].setString("Enamy left");
    SFMLText[8].setPosition(0, 30);
    SFMLText[8].setFont(font);
    SFMLText[8].setFillColor(sf::Color::Red);
    SFMLText[8].setCharacterSize(20);
    SFMLText[9].setPosition(120, 30);
    SFMLText[9].setFont(font);
    SFMLText[9].setFillColor(sf::Color::Red);
    SFMLText[9].setCharacterSize(20);
}

GameControler::~GameControler()
{

}

std::string GameControler::getNextState() const
{
    return nextState;
}

void GameControler::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            board.SetGameState(PAUZA);
            nextState = "PAUZA";
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            board.swapDirection(0);
            hero.Move(board.getDirection(), true);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            board.swapDirection(1);
            hero.Move(board.getDirection(), true);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            board.swapDirection(2);
            hero.Move(board.getDirection(), true);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            board.swapDirection(3);
            hero.Move(board.getDirection(), true);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (board.getDirection() == right || board.getDirection() == left)
            {
                music.stop();
                music.play();
                hero.Attack(board.getDirection());
            }
        }

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

void GameControler::updateModel()
{
    if (board.getState() == GAMELOSE || board.getState() == GAMEWIN)
    {
        reset();

    }
    hero.Update();
    enemy.Update();
    for (int x = 0; x < 100; ++x)
    {
        if (hero.getBulet()[x].isBullet)
        {
            bullet[x].setFillColor(sf::Color::Red);
            bullet[x].setPosition((hero.getBulet()[x].PositionY + 1 - board.getMoveCounter()) * 16,
                                  (hero.getBulet()[x].PositionX + 1) * 20);
            bullet[x].setRadius(3);
        } else
            bullet[x].setRadius(0);

        if (hero.IsAlive())
        {
            if (lastY < hero.GetPositionY() || lastdistance > board.getDistance() || hero.GetPositionX() != lastX)
            {
                lastdistance = board.getDistance();
                lastY = hero.GetPositionY();
                lastX = hero.GetPositionX();

                //glowny bochater
                if (board.getDirection() == right)
                    if (i > 3)
                        i = 1;
                if (board.getDirection() == left)
                    if (i > 6 || i < 4)
                        i = 4;
                if (board.getDirection() == up || board.getDirection() == down)
                    i = 4;
                SFMLSprite[1].setTexture(SFMLTexture[i]);
                ++i;
                SFMLSprite[1].setPosition(sf::Vector2f((hero.GetPositionY()) * 16 - board.getMoveCounter() * 16,
                                                       (hero.GetPositionX()) * 20));
            }
        } else
            SFMLSprite[1].setScale(0, 0);

        if (x % 2 == 0)
        {
            if (k > 49)
                k = 0;
            if (!enemy.getCharacter()[x].IsAlive())
                SFMLEnemy[k].setScale(0, 0);

            else
            {
                SFMLEnemy[k].setScale(1, 1);
                if (lastEnemyY[x] != enemy.getCharacter()[x].GetPositionY())
                {
                    lastEnemyY[x] = enemy.getCharacter()[x].GetPositionY();
                    SwapStateTexture(k);
                }
            }

            SFMLEnemy[k].setTexture(SFMLTexture[7]);
            SFMLEnemy[k].setPosition((enemy.getCharacter()[x].GetPositionY() - board.getMoveCounter()) * 16,
                                     enemy.getCharacter()[x].GetPositionX() * 20);
            ++k;
        } else
        {
            if (g > 49)
                g = 0;
            if (!enemy.getCharacter()[x].IsAlive())
                SFMLEnemy2[g].setScale(0, 0);
            else
            {
                SFMLEnemy2[g].setScale(1, 1);
                if (lastEnemyY[x] != enemy.getCharacter()[x].GetPositionY())
                {
                    lastEnemyY[x] = enemy.getCharacter()[x].GetPositionY();

                    SwapStateTexture2(g);
                }
            }
            SFMLEnemy2[g].setTexture(SFMLTexture2[7]);
            SFMLEnemy2[g].setPosition(
                    (enemy.getCharacter()[x].GetPositionY() - board.getMoveCounter() - 1) * 16,
                    enemy.getCharacter()[x].GetPositionX() * 20);
            ++g;
        }
        if (enemy.getBuletEnemy()[x].isBullet)
        {
            bullet2[x].setFillColor(sf::Color::Blue);
            bullet2[x].setPosition((enemy.getBuletEnemy()[x].PositionY + 1 - board.getMoveCounter()) * 16,
                                   (enemy.getBuletEnemy()[x].PositionX + 1) * 20);
            bullet2[x].setRadius(3);
        } else
        {
            bullet2[x].setRadius(0);
        }
    }

    SFMLSprite[0].setPosition(-(board.getMoveCounter()) * 16, 0);

    SFMLText[7].setString(std::to_string(hero.GetLife()));
    int z = 0;
    for (int l = 0; l < 100; ++l)
    {
        if (enemy.getCharacter()[l].IsAlive())
            ++z;
    }
    SFMLText[9].setString(std::to_string(z));
}

void GameControler::draw(sf::RenderWindow &win)
{
    win.draw(SFMLSprite[0]);
    win.draw(SFMLText[6]);
    win.draw(SFMLText[7]);
    win.draw(SFMLText[8]);
    win.draw(SFMLText[9]);
    win.draw(SFMLSprite[1]);

    for (int x = 0; x < 100; ++x)
    {
        win.draw(bullet[x]);
        win.draw(bullet2[x]);
        if (x < 50)
        {
            win.draw(SFMLEnemy[x]);
            win.draw(SFMLEnemy2[x]);
        }
    }
}

void GameControler::onEnter(const std::string &data)
{
    nextState = this->getStateID();
}

std::string GameControler::onExit()
{
    return "";
}

void GameControler::reset()
{
    hero.reset();
    enemy.Reset();
    SFMLSprite[3].setPosition(0, 0);
    SFMLSprite[4].setPosition(-1598, 0);
    SFMLSprite[1].setPosition
            (sf::Vector2f((hero.GetPositionY()) * 16 - board.getMoveCounter() * 16, (hero.GetPositionX()) * 20));
    lastX = hero.GetPositionX();

    SFMLSprite[1].setScale(1, 1);
    nextState = "GAMEOVER";
}

void GameControler::SwapStateTexture(int idx)
{
    if (enemy.getCharacter()[idx].getDirection() == right)
    {
        if (nextTexture[idx] < 6 || nextTexture[idx] > 9)
            nextTexture[idx] = 7;
        else
            ++nextTexture[idx];
    } else
    {
        if (nextTexture[idx] < 9 || nextTexture[idx] > 12)
            nextTexture[idx] = 10;
        else
            ++nextTexture[idx];
    }
}

void GameControler::SwapStateTexture2(int idx)
{
    if (enemy.getCharacter()[idx].getDirection() == right)
    {
        if (nextTexture2[idx] < 7 || nextTexture2[idx] > 9)
            nextTexture2[idx] = 7;
        else
            ++nextTexture2[idx];
    } else
    {
        if (nextTexture2[idx] < 9 || nextTexture2[idx] > 12)
            nextTexture2[idx] = 10;
        else
            ++nextTexture2[idx];
    }
}
