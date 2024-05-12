#include "GameEngine.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Running main" << std::endl;
    GameEngine game;

    if(!game.IsRunning())
    {
        std::cout << "Game::Init failed" << std::endl;
        return -1;
    }

    while(game.IsRunning())
    {
        game.Update();
    }

    return 0;
}