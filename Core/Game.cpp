#include "Game.h"
#include <iostream> // std::cout, std::endl
#include <SDL2/SDL.h> // SDL_Init, SDL_Quit
#include "../Rendering/GameWindow.h"
#include "../Rendering/RenderInstanceManager.h"
//#include "../Rendering/Renderer.h"

Game::Game(token)
{
    std::cout << "Game instance created" << std::endl;
}

Game::~Game()
{
    std::cout << "Game instance destroyed" << std::endl;
}

bool Game::Init()
{
    bool ret = 0;

    ret = SDL_Init(SDL_INIT_EVERYTHING);
    if (ret != 0)
    {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return false;
    }

    ret = GameWindow::instance().Init();
    if (!ret)
    {
        std::cout << "GameWindow::Init failed" << std::endl;
        return false;
    }

    ret = RenderInstanceManager::instance().AddRenderer("main");
    if (!ret)
    {
        std::cout << "GameRenderer::Init failed" << std::endl;
        return false;
    }

    _running = true;
    return true;
}

void Game::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                _running = false;
                break;

            default:
                break;
        }
    }

    SDL_RenderClear(RenderInstanceManager::instance().GetRenderer("main"));
    SDL_SetRenderDrawColor(RenderInstanceManager::instance().GetRenderer("main"), 0, 0, 0, 255);
    SDL_RenderPresent(RenderInstanceManager::instance().GetRenderer("main"));
}