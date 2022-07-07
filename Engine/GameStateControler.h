//
// Created by Karol on 20.06.2020.
//

#ifndef GREENBERET_GAMESTATECONTROLER_H
#define GREENBERET_GAMESTATECONTROLER_H
#include <SFML/Graphics.hpp>

class GameStateController
{
    const std::string myStateID;
public:
    explicit GameStateController(const std::string & stateId) : myStateID(stateId) {}
    std::string getStateID() const { return myStateID; }
    // do zaimplementowania w klasach pochodnych
    virtual std::string getNextState() const = 0;
    virtual void handleEvent ( const sf::Event & event ) = 0;
    virtual void updateModel() = 0;
    virtual void draw(sf::RenderWindow & win) = 0;

    virtual void onEnter(const std::string & data) = 0;
    virtual std::string onExit() = 0;
};





#endif //GREENBERET_GAMESTATECONTROLER_H
