#pragma once

#include "../Templates/Singleton.h"
#include <map>
#include <memory>
#include <SDL2/SDL.h> // SDL_Renderer

//class SDL_Renderer;

class RenderInstanceManager final : public Singleton<RenderInstanceManager>
{
private:
    std::map<const char*, std::unique_ptr<SDL_Renderer>> _renderers;

public:
    RenderInstanceManager(token);
    ~RenderInstanceManager();

    SDL_Renderer* AddRenderer(const char* id);
    void RemoveRenderer(const char* id);
    void ClearRenderers();

    SDL_Renderer* GetRenderer(const char* id);
};