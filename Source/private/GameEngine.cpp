#include "../public/GameEngine.h"
#include <iostream> // std::cout, std::endl
#include <SDL2/SDL.h> // SDL_Init, SDL_Quit
#include "GameWindow.h"
#include "RenderInstanceManager.h"
#include "InputManager.h"
#include "LevelManager.h"
#include "LevelFactory.h"
#include "DeltaTime.h"

GameEngine::GameEngine()
{
    int ret = SDL_Init(SDL_INIT_EVERYTHING);
    if (ret != 0)
    {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return;
    }

    _running = GameWindow::instance().Init();
    if (!_running)
    {
        std::cout << "GameWindow::Init failed" << std::endl;
        return;
    }

    if (!RenderInstanceManager::instance().CreateRaycastRenderer())
    {
        std::cout << "GameRenderer::Init failed" << std::endl;
        return;
    }

    RenderInstanceManager::instance().GetRenderer(0)->Init();

    _running = InputManager::instance().Init();
    if (!_running)
    {
        std::cout << "InputManager::Init failed" << std::endl;
        return;
    }

    LevelManager::instance().LoadLevel( LevelFactory::CreateLevel());
    LevelManager::instance().BeginPlay();

}

void GameEngine::Update()
{
    Time::UpdateDeltaTime();

    // SDL Event handling loop
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
                // Quit game on esc
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    _running = false;
                }
                break;
            case SDL_QUIT:
                _running = false;
                break;

            default:
                break;
        }
    }

    // Update level
    LevelManager::instance().UpdateLevel();

    // Updates input state and performs any bound callbacks
    InputManager::instance().Update();

    RenderInstanceManager::instance().GetRenderer(0)->DrawFrame();
    RenderInstanceManager::instance().GetRenderer(0)->Present();

    // Calculate average fps over past 10 seconds
    _frameCount++;
    _frameTime += Time::GetDeltaTime();
    if (_frameTime >= 10.f)
    {
        std::cout << "Average FPS: " << _frameCount / _frameTime << std::endl;
        _frameCount = 0;
        _frameTime = 0.f;
    }
}