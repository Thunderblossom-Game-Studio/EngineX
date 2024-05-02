#pragma once

#include "Renderer.h"

#include <SDL.h>
#include "LevelManager.h"
#include "Player.h"
#include "Config.h"

class RaycastRenderer : public GameRenderer
{
private:
    //std::shared_ptr<Level> _mainLevel = nullptr;
    //std::shared_ptr<Player> _player = nullptr;
    std::vector<std::vector<Wall*>> _worldMap;

    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    int renderLoop = 0;

public:
    RaycastRenderer(SDL_Window* pWindow, const char* id);
    ~RaycastRenderer();

    void Init() override;

    void DrawFrame() override;

};