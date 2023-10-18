#pragma once

#include "Renderer.h"

#include <SDL2/SDL.h>
#include "../Level/LevelManager.h"
#include "../GameObjects/Player.h"
#include "../Globals/Config.h"

class RaycastRenderer : public GameRenderer
{
private:
    std::shared_ptr<Level> _mainLevel = nullptr;
    std::shared_ptr<Player> _player = nullptr;
    std::vector<std::vector<int>> worldMap;

    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    int renderLoop = 0;

public:
    RaycastRenderer(SDL_Window* pWindow);
    ~RaycastRenderer();

    void Init() override;

    void DrawFrame() override;

};