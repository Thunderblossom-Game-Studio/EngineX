#include "Game.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Running main" << std::endl;

    bool running = Game::instance().Init();
    if(!running)
    {
        std::cout << "Game::Init failed" << std::endl;
        return -1;
    }

    while(Game::instance().IsRunning())
    {
        Game::instance().Update();
    }

    return 0;
}