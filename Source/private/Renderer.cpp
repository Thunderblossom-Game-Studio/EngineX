#include "Renderer.h"

#include <iostream> // std::cout, std::endl
#include <SDL2/SDL.h> // SDL_CreateRenderer, SDL_DestroyRenderer, SDL_RENDERER_ACCELERATED, SDL_RENDERER_PRESENTVSYNC
#include "GameWindow.h" // Game::GetWindow

GameRenderer::GameRenderer(SDL_Window* pWindow, const char* id)
    : _id(id)
{
    _pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (_pRenderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
    }
    std::cout << "Game renderer created" << std::endl;

    _pCamera = new Camera(Vector2(1.f,1.f), Vector2(1.f,1.f), Vector2(1.f,1.f));
}

GameRenderer::~GameRenderer()
{
    SDL_DestroyRenderer(_pRenderer);
    std::cout << "Game renderer destroyed" << std::endl;
}

void GameRenderer::SetDrawColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(_pRenderer, r, g, b, a);
}

void GameRenderer::RenderClear()
{
    SDL_RenderClear(_pRenderer);
}

void GameRenderer::Present()
{
    SDL_RenderPresent(_pRenderer);
}

Camera* GameRenderer::GetCamera()
{
    std::cout << _id << std::endl;

    if(_pCamera)
        return _pCamera;
    else
    {
        std::cout << "Camera not found" << std::endl;
        return nullptr;
    }
}