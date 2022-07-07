//d
// Created by Karol on 21.05.2020.
//

#include "SFMLView.h"
#include <iostream>
#include <cstring>

SFMLView::SFMLView(Hero &hero,Enemy &enemy,Board &board,Character & character)
: hero(hero), board(board),character(character),enemy(enemy)
{

    if (!font.loadFromFile("arialbd.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    SFMLTexture[1].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/walk3bochater.png");
    SFMLTexture[2].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/walk5bochater.png");
    SFMLTexture[3].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/walk6bochater.png");
    SFMLTexture[4].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewywalk3bochater.png");
    SFMLTexture[5].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewywalk5bochater.png");
    SFMLTexture[6].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewywalk6bochater.png");
    //przeciwnik1
    SFMLTexture[7].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/bandyta1.png");
    SFMLTexture[8].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/bandyta2.png");
    SFMLTexture[9].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/bandyta3.png");
    SFMLTexture[10].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/Lewybandyta1.png");
    SFMLTexture[11].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/Lewybandyta2.png");
    SFMLTexture[12].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewybandyta3.png");
    SFMLTexture[13].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/char2.png");
    SFMLTexture[14].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/char3.png");
    SFMLTexture[15].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/char4.png");

    SFMLTexture[16].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewychar1.png");
    SFMLTexture[17].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewychar2.png");
    SFMLTexture[18].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/lewychar3.png");


    //SFMLTexture[10].loadFromFile("C:/Users/Karol/OneDrive/Pulpit/GreenBeretPictures/dog1.png");
    //SFMLTexture[11].loadFromFile("C:/Users/Karol/OneDrive/Pulpit/GreenBeretPictures/dog3.png");
    //SFMLTexture[12].loadFromFile("C:/Users/Karol/OneDrive/Pulpit/GreenBeretPictures/dog2.png");
    SFMLTexture[0].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/plansza.png");
    SFMLTexture[19].loadFromFile("C:/Users/Karol/CLionProjects/GreenBeret/Images/Menu.png");


    SFMLSprite[0].setTexture(SFMLTexture[0]);
    SFMLSprite[1].setTexture(SFMLTexture[1]);

this->Reset();

}
void SFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    switch(board.getState())
    {
        case START:
            target.draw(SFMLSprite[4],states);
            target.draw(SFMLSprite[3],states);
            for (int l = 0; l <3 ; ++l)
            {

                target.draw(rectengle[l], states);
                target.draw(SFMLText[l], states);

            }
            target.draw(SFMLText[9], states);
            break;
        case LEVEL:
            target.draw(SFMLSprite[4],states);

            target.draw(SFMLSprite[3],states);


/*            for (int l = 0; l <4 ; ++l)
            {

                target.draw(rectengle[l], states);
                target.draw(SFMLText[l], states);

            }*/
            for (int l = 3; l <6 ; ++l)
            {
                target.draw(rectengle[l + 3], states);
                target.draw(SFMLText[l]);
            }
            break;
        case PAUZA:
            for (int m = 3; m <6 ; ++m)
            {
                target.draw(rectengle[m], states);
                target.draw(SFMLText[m+8], states);
            }
            break;
            case RUNNING:

target.draw(SFMLSprite[0],states);
        //target.draw(SFMLSprite[2],states);
   target.draw(SFMLSprite[1],states);
            target.draw(SFMLText[6],states);
            target.draw(SFMLText[7],states);
            target.draw(SFMLText[8],states);
            target.draw(SFMLText[9],states);

            for (int x = 0; x <100 ; ++x)
    {
        target.draw(bullet[x],states);
        target.draw(bullet2[x],states);
        if(x<50)
        {
            target.draw(SFMLEnemy[x], states);
            target.draw(SFMLEnemy2[x], states);
        }}


            break;
//target.draw(SFMLSprite[7],states);
        case GAMEWIN:
            target.draw(SFMLSprite[0],states);
            target.draw(SFMLSprite[1],states);
    target.draw(SFMLText[10],states);
    break;

    }
}

void SFMLView::Update()
{
    std::string levelText[3]={"Easy","Normal","Hard"};
    std::string Pauza[3]={"Czy na pewno chcesz zakonczyć gre","tak","nie"};
    //poprzenosic do konstruktora zeczy nie potrzebne
    std::string text[4] = {"zaczanij gre", "wybierz poziom", "zakoncz gre", "blabal"};
    SFMLSprite[3].setTexture(SFMLTexture[19]);
    SFMLSprite[4].setTexture(SFMLTexture[19]);
    SFMLSprite[3].move(0.5, 0);
    SFMLSprite[4].move(0.5, 0);
    if (SFMLSprite[3].getPosition().x > 1600)
    {
        SFMLSprite[3].setPosition(0, 0);
        SFMLSprite[4].setPosition(-1598, 0);
    }

    //wybor menu







    ++w;
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
//prawdopodobnie niepotrzebne
//oponents
//move


        if (w % 5 == 0)
        {
            w = 0;

            if (x % 2 == 0)
            {

                if (k > 49)
                    k = 0;

                //trzeba zmienic postac tylko znika ale zostaje nadal na planszy
                if (!enemy.getCharacter()[x].IsAlive())
                    SFMLEnemy[k].setScale(0, 0);
                else
                {
                    SFMLEnemy[k].setScale(1, 1);
                 //   std::cout << "pozx=" << enemy.getCharacter()[x].GetPositionX();
                   // std::cout << "pozy=" << enemy.getCharacter()[x].GetPositionY() << std::endl;
                    //std::cout << "HetoX" << hero.GetPositionX();
                    //std::cout << "heroY" << hero.GetPositionY() << std::endl;
                   // SFMLEnemy[k].setScale(1, 1);
                    //   std::cout<<"kierunek_j="<<enemy.getCharacter()[x].getDirection();
                    // std::cout<<"x="<<x;
                    if (enemy.getCharacter()[x].getDirection() == right)
                    {
                        //    std::cout << "\nbefore j=" << j;
                        if (j > 8)
                            j = 6;

                    }
                    if (enemy.getCharacter()[x].getDirection() == left)
                    {
                        if (j > 11 || j < 9)
                            j = 9;
                    }
                    ++j;
                    //  std::cout << "j=" << j;

                }
                SFMLEnemy[k].setTexture(SFMLTexture[j]);

                SFMLEnemy[k].setPosition((enemy.getCharacter()[x].GetPositionY() - board.getMoveCounter()) * 16,
                                         enemy.getCharacter()[x].GetPositionX() * 20);

                ++k;
            } else
            {
                if (g > 49)
                    g = 0;


                // std::cout << "kierundk" << enemy.getCharacter()[x].getDirection();


                //to samo co wyzej
                if (!enemy.getCharacter()[x].IsAlive())
                    SFMLEnemy2[g].setScale(0, 0);
                else
                {
                    SFMLEnemy2[g].setScale(1, 1);
                //    std::cout << "pozXS=" << enemy.getCharacter()[x].GetPositionX();
                  //  std::cout << "pozYS=" << enemy.getCharacter()[x].GetPositionY() << std::endl;
                    //std::cout << "\ns before=" << s;
                    //std::cout<<"x="<<x;
                    //std::cout<<"kierunek_s="<<enemy.getCharacter()[x].getDirection();
                    if (enemy.getCharacter()[x].getDirection() == right)
                    {

                        if (s > 14)
                            s = 12;
                    }
                    if (enemy.getCharacter()[x].getDirection() == left)
                    {
                        if (s > 17 || s < 15)
                            s = 15;
                    }
                    ++s;
             //       std::cout << "s" << s;
                }

                SFMLEnemy2[g].setTexture(SFMLTexture[s]);


                SFMLEnemy2[g].setPosition(
                        (enemy.getCharacter()[x].GetPositionY() - board.getMoveCounter() - 1) * 16,
                        enemy.getCharacter()[x].GetPositionX() * 20);


                ++g;
            }

        }
//atack
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
    /*    int z = 0;
     for (int l = 0; l < 100; ++l)
     {
         if (enemy.getCharacter()[l].IsAlive())
         {
             ++z;
         }
     }
 }*/
    //  std::cout<<"\npozostała liczba wrogów="<<z;
//planszaddd
//blokuje sie ekran
    //jesli wszyscy sa zabici ruszyc auto ekran

    switch (board.getState())
    {
        case RUNNING:
        {
            SFMLSprite[0].setPosition(-(board.getMoveCounter()) * 16, 0);
            SFMLText[6].setString("Lives");
            SFMLText[6].setPosition(0, 0);
            SFMLText[6].setFont(font);
            SFMLText[6].setFillColor(sf::Color::Red);
            SFMLText[6].setCharacterSize(20);
            SFMLText[7].setString(std::to_string(hero.GetLife()));
            SFMLText[7].setPosition(60, 0);
            SFMLText[7].setFont(font);
            SFMLText[7].setFillColor(sf::Color::Red);
            SFMLText[7].setCharacterSize(14);
            SFMLText[8].setString("Enamy left");
            SFMLText[8].setPosition(0, 30);
            SFMLText[8].setFont(font);
            SFMLText[8].setFillColor(sf::Color::Red);
            SFMLText[8].setCharacterSize(20);


            int z = 0;
            for (int l = 0; l < 100; ++l)
            {
                if (enemy.getCharacter()[l].IsAlive())
                    ++z;
            }
            SFMLText[9].setString(std::to_string(z));
            SFMLText[9].setPosition(120, 30);
            SFMLText[9].setFont(font);
            SFMLText[9].setFillColor(sf::Color::Red);
            SFMLText[9].setCharacterSize(20);
            break;
        }
        case GAMEWIN:
        {
            if (SFMLSprite[1].getPosition().x < 1600)
            {
                //  std::cout << "x=" << SFMLSprite[1].getPosition().x;
                // std::cout << "x=" << SFMLSprite[1].getPosition().x << std::endl;
                if (w == 9)
                {
                    w = 0;
                    if (i > 2)
                        i = 0;
                    ++i;
                    SFMLSprite[1].setTexture(SFMLTexture[i]);
                }
                SFMLSprite[0].move(-4, 0);
                SFMLSprite[1].move(4, 0);
                if (SFMLSprite[1].getPosition().x > 300)
                {
                    SFMLText[10].setString("wygrana");
                    SFMLText[10].setPosition(700, 300);
                    SFMLText[10].setFont(font);
                    SFMLText[10].rotate(3);
                    SFMLText[10].setFillColor(sf::Color::Green);
                    SFMLText[10].setCharacterSize(100);
                }
            } else
            {
                board.SetGameState(START);
            }

            break;
        }
        case PAUZA:
            rectengle[3].setPosition(500,300);
            rectengle[3].setFillColor(sf::Color::Blue);
            rectengle[3].setSize(sf::Vector2f(600,300));
            rectengle[4].setPosition(550,500);
            rectengle[4].setFillColor(sf::Color::White);
            rectengle[4].setSize(sf::Vector2f(200,50));

            rectengle[4].setOutlineThickness(20);
            rectengle[5].setOutlineThickness(20);
            rectengle[5].setPosition(850,500);
            rectengle[5].setFillColor(sf::Color::White);
            rectengle[5].setSize(sf::Vector2f(200,50));
            SFMLText[11].setFont(font);
            SFMLText[11].setCharacterSize(30);
            SFMLText[11].setPosition(rectengle[3].getPosition().x+10,rectengle[3].getPosition().y+10);
            SFMLText[11].setFillColor(sf::Color::Black);
            SFMLText[11].setString(Pauza[0]);
            SFMLText[12].setFont(font);
            SFMLText[12].setCharacterSize(30);
            SFMLText[12].setPosition(rectengle[4].getPosition().x+10,rectengle[4].getPosition().y+10);
            SFMLText[12].setFillColor(sf::Color::Black);
            SFMLText[12].setString(Pauza[1]);
            SFMLText[13].setFont(font);
            SFMLText[13].setCharacterSize(30);
            SFMLText[13].setPosition(rectengle[5].getPosition().x+10,rectengle[5].getPosition().y+10);
            SFMLText[13].setFillColor(sf::Color::Black);
            SFMLText[13].setString(Pauza[2]);
            break;
            case LEVEL:
        //        std::cout<<"//n/nle";
                rectengle[6].setPosition(100,350);
            rectengle[6].setFillColor(sf::Color::Blue);
            rectengle[6].setSize(sf::Vector2f(350,100));
            rectengle[6].setOutlineColor(sf::Color::Black);
            rectengle[6].setOutlineThickness(15);

            rectengle[7].setPosition(600,350);
            rectengle[7].setFillColor(sf::Color::Blue);
            rectengle[7].setSize(sf::Vector2f(350,100));
            rectengle[7].setOutlineColor(sf::Color::Black);
            rectengle[7].setOutlineThickness(15);

            rectengle[8].setPosition(1100,350);
            rectengle[8].setFillColor(sf::Color::Blue);
            rectengle[8].setSize(sf::Vector2f(350,100));
            rectengle[8].setOutlineColor(sf::Color::Black);
            rectengle[8].setOutlineThickness(15);
            for (int n = 3; n <6 ; ++n)
            {
                SFMLText[n].setString(levelText[n-3]);
                SFMLText[n].setFillColor(sf::Color::Black);
                SFMLText[n].setPosition(rectengle[n+3].getPosition().x+50,rectengle[n+3].getPosition().y+50);
                SFMLText[n].setFont(font);
                SFMLText[n].setCharacterSize(20);
            }
            rectengle[menuChose+6].setOutlineColor(sf::Color::Yellow);



            break;
        case START:
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
                SFMLText[m].setFillColor(sf::Color::White);

                SFMLText[m].setFont(font);
                SFMLText[m].setCharacterSize(20);
                SFMLText[m].setString(text[m]);
            }
            SFMLText[9].setPosition(rectengle[1].getPosition().x+100,rectengle[1].getPosition().y+70);
            SFMLText[9].setCharacterSize(40);
            SFMLText[9].setFont(font);
            SFMLText[9].setFillColor(sf::Color::White);
            std::string x;
            switch(enemy.getLevel())
            {
                case 0:
                    SFMLText[9].setString("Obecny Poziom\nEasy");
                    break;
                case 1:
                    SFMLText[9].setString("Obecny Poziom\nNormal");
                    break;
                case 2:
                    SFMLText[9].setString("Obecny Poziom\nHard");
                    break;
            }

    }
}
void SFMLView::swap(Direction dir)
{

/*if(state==START)
LevelChose=0;
if(state==LEVEL)
    LevelChose=1;
    if(LevelChose!=LastLevelChose)
    {
        LastLevelChose=LevelChose;
        menuChose=0;
    }*/
    {if(dir==up)

    {

        --menuChose;
    if(menuChose<0)
        menuChose=2;
    //    std::cout<<"\n\nmenu="<<menuChose;
    }
        if(dir==down)
        {

            ++menuChose;
            if(menuChose>2)
                menuChose=0;
            std::cout<<"\n\nmenu="<<menuChose;

        }
        if(dir==left)
        {
          std::cout<<"\n\nmenu="<<menuChose;
            level = static_cast<Level>(menuChose);
            enemy.setLevel(level);


        }
        if(dir==right)
        {
            state = static_cast<GameState>(menuChose);
            std::cout<<"\n\nx="<<state;
            board.SetGameState(state);
        }

        }


            }

void SFMLView::Reset()
{
    SFMLSprite[3].setPosition(0, 0);
    SFMLSprite[4].setPosition(-1598, 0);
    SFMLSprite[1].setPosition
            (sf::Vector2f((hero.GetPositionY()) * 16 - board.getMoveCounter() * 16, (hero.GetPositionX()) * 20));
    lastX=hero.GetPositionX();
    SFMLSprite[1].setScale(1,1);
    w=0;
    h=0;
    menuChose=0;
    LastLevelChose=0;
    Update();
}

void SFMLView::SwapState(int i)
{

    {
        if (rectengle[4].getOutlineColor() == sf::Color::Yellow)
        {
            if (i == 0)
            rectengle[5].setOutlineColor(sf::Color::Yellow);

        else if(i==1)
                board.SetGameState(GAMELOSE);
            rectengle[4].setOutlineColor(sf::Color::White);
        }else
        {if (i == 0)
            {rectengle[4].setOutlineColor(sf::Color::Yellow);

        } else if(i==1)
board.SetGameState(RUNNING);
            rectengle[5].setOutlineColor(sf::Color::White);
        }
    }

}



