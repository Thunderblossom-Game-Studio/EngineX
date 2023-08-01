#include "RenderInstanceManager.h"

#include <iostream> // std::cout, std::endl
#include "GameWindow.h" // GameWindow::instance
#include <SDL2/SDL.h> // SDL_Renderer, SDL_CreateRenderer, SDL_DestroyRenderer

RenderInstanceManager::RenderInstanceManager(token)
{}

RenderInstanceManager::~RenderInstanceManager()
{
    std::cout << "Clearing renderers" << std::endl;
    ClearRenderers();
}

SDL_Renderer* RenderInstanceManager::AddRenderer(const char* id)
{
    if (_renderers.find(id) == _renderers.end())
    {
        _renderers[id] = std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>(SDL_CreateRenderer(GameWindow::instance().GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
        std::cout << "Renderer created" << std::endl;
    }

    return _renderers.at(id).get();
}

void RenderInstanceManager::RemoveRenderer(const char* id)
{
    if (_renderers.find(id) != _renderers.end())
    {
        _renderers.erase(id);
        std::cout << "Renderer destroyed" << std::endl;
    }
}

void RenderInstanceManager::ClearRenderers()
{
    _renderers.clear();
}

SDL_Renderer* RenderInstanceManager::GetRenderer(const char* id)
{
    if (_renderers.find(id) != _renderers.end())
    {
        return _renderers.at(id).get();
    }
    std::cout << "Renderer not found" << std::endl;
    return nullptr;
}