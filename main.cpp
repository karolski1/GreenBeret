#include<SFML/Graphics.hpp>
#include "Engine/Board.h"
#include "Engine/Character.h"
#include "Engine/SFMLView.h"
#include "Characters/Hero.h"
#include "Characters/Enemy.h"
#include <SFML/Graphics.hpp>
#include "Engine/GameManager.h"
#include <memory>
#include "States/Game/GameControler.h"
#include "States/LevelOptions/LevelOptionsControler.h"
#include "States/MainMenu/MainMenuControler.h"
#include "States/Pauza/PauzaControler.h"
#include "States/GameOver/GameOverControler.h"

int main()
{
    constexpr int Screan_width = 1600, Screan_height = 900;
    sf::RenderWindow win(sf::VideoMode(Screan_width, Screan_height), "GreenBeret");
    GameManager mgr(win);
    Character ch;
    Board board;
    Hero h(board);
    Enemy e(board, h);
    mgr.registerState(std::make_shared<PauzaControler>(board));
    mgr.registerState(std::make_shared<GameOverControler>(board));
    mgr.registerState(std::make_shared<MainMenuControler>(e, board));
    mgr.registerState(std::make_shared<LevelOptionsControler>(e));
    mgr.registerState(std::make_shared<GameControler>(h, e, board, ch));
    mgr.changeState("START");
    mgr.run();
    return 0;
}
