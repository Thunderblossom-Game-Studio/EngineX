#include "RenderInstanceManager.h"

#include <iostream> // std::cout, std::endl
#include "GameWindow.h" // GameWindow::instance
//#include <SDL2/SDL.h> // SDL_Renderer, SDL_CreateRenderer, SDL_DestroyRenderer

RenderInstanceManager::RenderInstanceManager(token)
{}

RenderInstanceManager::~RenderInstanceManager()
{
    ClearRenderers();
}

SDL_Renderer* RenderInstanceManager::AddRenderer(const char* id)
{
    if (_renderers.find(id) == _renderers.end())
    {
        auto renderer = SDL_CreateRenderer(GameWindow::instance().GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        _renderers[id] = std::unique_ptr<SDL_Renderer>(renderer);
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