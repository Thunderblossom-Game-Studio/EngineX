#pragma once

#include "../Templates/Singleton.h"
#include <map>
#include <memory>
//#include <SDL2/SDL.h> // SDL_Renderer, SDL_DestroyRenderer

#include "Renderer.h"
#include "RaycastRenderer.h"

class RenderInstanceManager final : public Singleton<RenderInstanceManager>
{
private:
    // struct SDLRendererDestroyer
    // {
    //     void operator()(SDL_Renderer* pRenderer) const
    //     {
    //         SDL_DestroyRenderer(pRenderer);
    //     }
    // };


    //std::map<const char*, std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>> _renderers;
    std::map<const char*, std::unique_ptr<GameRenderer>> _renderers;

public:
    RenderInstanceManager(token);
    ~RenderInstanceManager();

    //SDL_Renderer* AddRenderer(const char* id);
    GameRenderer* AddRenderer(const char* id);
    RaycastRenderer* AddRaycastRenderer(const char* id);
    void RemoveRenderer(const char* id);
    void ClearRenderers();

    //SDL_Renderer* GetRenderer(const char* id);
    GameRenderer* GetRenderer(const char* id);
};