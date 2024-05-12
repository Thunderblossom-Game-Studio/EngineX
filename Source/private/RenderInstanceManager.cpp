#include "RenderInstanceManager.h"

#include <iostream> // std::cout, std::endl
#include "GameWindow.h" // GameWindow::instance
#include <SDL.h> // SDL_Renderer, SDL_CreateRenderer, SDL_DestroyRenderer

#include "Renderer.h" // GameRenderer
#include "RaycastRenderer.h" // RaycastRenderer

RenderInstanceManager::RenderInstanceManager(token)
{}

RenderInstanceManager::~RenderInstanceManager()
{
    std::cout << "Clearing renderers" << std::endl;
    ClearRenderers();
}

std::shared_ptr<GameRenderer> RenderInstanceManager::AddRenderer()
{
    std::cout << "Default Renderer addition not implemented" << std::endl;
    return nullptr;
}

std::shared_ptr<RaycastRenderer> RenderInstanceManager::CreateRaycastRenderer()
{
    _renderers.push_back(std::make_shared<RaycastRenderer>(GameWindow::instance().GetWindow(), "main"));

    return std::dynamic_pointer_cast<RaycastRenderer>(_renderers.back());
}

void RenderInstanceManager::RemoveRenderer()
{
    std::cout << "Render removal not implemented" << std::endl;
}

void RenderInstanceManager::ClearRenderers()
{
    _renderers.clear();
    std::cout << "Destroyed all renderers" << std::endl;
}

std::shared_ptr<GameRenderer> RenderInstanceManager::GetRenderer(int index)
{
    if(index < _renderers.size())
        return _renderers[index];

    printf("Renderer index %d out of bounds\n", index);
    return nullptr;
}