//
// Created by Karol on 20.06.2020.
//
#include <iostream>
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow & win ) : window(win)
{
}

void GameManager::changeState(const std::string &newState)
{
    if (stateMap.find(newState) == stateMap.end())
        throw GameStateException(newState);

    std::string rv = "";
    if (currentStatePtr != nullptr)
        rv = currentStatePtr->onExit();

    currentStatePtr = stateMap [ newState ];
    currentStatePtr->onEnter(rv);
}

void GameManager::run()
{
    while (window.isOpen())
    {
        std::string currentState = currentStatePtr->getStateID();
        std::string nextState = currentStatePtr->getNextState();

        if (currentState != nextState)
        {
            changeState(nextState);
        }


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            currentStatePtr->handleEvent(event);
        }

        currentStatePtr->updateModel();

        window.clear(sf::Color(120, 120, 120));

        currentStatePtr->draw(window);

        window.display();
    }
}

void GameManager::registerState(std::shared_ptr<GameStateController> state)
{
    std::string id = state->getStateID();

    stateMap[id] = state;
    std::cout<<"id="<<id<<"\n stateMap[id]="<<stateMap[id]<<"\n";
}
