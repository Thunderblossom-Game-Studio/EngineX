#pragma once

#include "../Templates/Singleton.h"

class SDL_Window;
class SDL_Renderer;

class GameRenderer
{
protected:
    SDL_Renderer* _pRenderer = nullptr;

public:
    GameRenderer(SDL_Window* pWindow);
    ~GameRenderer();

    void SetDrawColor(int r, int g, int b, int a);
    void RenderClear();
    void Present();
    SDL_Renderer* GetRenderer() { return _pRenderer; }
    virtual void DrawFrame() {};
    virtual void Init() {};
};