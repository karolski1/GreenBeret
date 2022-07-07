//
// Created by Karol on 21.06.2020.
//

#ifndef GREENBERET_PAUZACONTROLER_H
#define GREENBERET_PAUZACONTROLER_H

#include "../../Engine/GameStateControler.h"
#include "../../Engine/Board.h"

class PauzaControler: public GameStateController
    {
        sf::Font font;

        sf::Text SFMLText[14];
        sf::RectangleShape rectengle[10];
        std::string text[3] = {"Czy jestes pewien ze chcesz zakonczyc gre?", "tak", "nie"};
        std::string nextState;
        int menuChose;
        Board & board;

    public:
    explicit PauzaControler(Board & b);
        virtual ~PauzaControler();

        virtual std::string getNextState() const;
        virtual void handleEvent ( const sf::Event & event ) ;
        virtual void updateModel() ;
        virtual void draw(sf::RenderWindow & win) ;

        virtual void onEnter(const std::string & data) ;
        virtual std::string onExit() ;
        void swap();
    void Mychoice();
};


#endif //GREENBERET_PAUZACONTROLER_H
