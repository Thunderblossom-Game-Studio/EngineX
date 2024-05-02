#include "public/Game.h"
#include <iostream>

int main(int argc, char** argv)
{
    bool running = Game::instance().Init();
    if(!running)
    {
        std::cout << "Game::Init failed" << std::endl;
        return -1;
    }

    while(running)
    {
        Game::instance().Update();
        running = Game::instance().IsRunning();
    }

    return 0;
}