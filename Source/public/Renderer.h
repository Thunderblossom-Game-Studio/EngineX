#pragma once

#include "Singleton.h"
#include "Camera.h"

class SDL_Window;
class SDL_Renderer;

class GameRenderer
{
private:
    const char* _id;

protected:
    SDL_Renderer* _pRenderer = nullptr;
    Camera* _pCamera;

public:
    GameRenderer(SDL_Window* pWindow, const char* id);
    virtual ~GameRenderer();

    void SetDrawColor(int r, int g, int b, int a);
    void RenderClear();
    void Present();
    SDL_Renderer* GetRenderer() { return _pRenderer; }
    virtual void DrawFrame() {};
    virtual void Init() {};

    Camera* GetCamera();
};