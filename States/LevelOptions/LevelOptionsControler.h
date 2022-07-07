//
// Created by Karol on 20.06.2020.
//

#ifndef GREENBERET_LEVELOPTIONSCONTROLER_H
#define GREENBERET_LEVELOPTIONSCONTROLER_H
#include "../../Engine/GameStateControler.h"
#include "../../Characters/Enemy.h"

class LevelOptionsControler:public GameStateController
    {
        std::string nextState;
    sf::Font font;

    sf::Text SFMLText[14];
    sf::RectangleShape rectengle[10];
    std::string levelText[3]={"Easy","Normal","Hard"};
    int menuChose=0;
    Level level;
    Enemy & enemy;
    public:
        LevelOptionsControler(Enemy &e);
        virtual ~LevelOptionsControler();

        virtual std::string getNextState() const;
        virtual void handleEvent ( const sf::Event & event ) ;
        virtual void updateModel() ;
        virtual void draw(sf::RenderWindow & win) ;

        virtual void onEnter(const std::string & data) ;
        virtual std::string onExit() ;
    void swap(Direction dir);
    void MyChoice();

    };




#endif //GREENBERET_LEVELOPTIONSCONTROLER_H
