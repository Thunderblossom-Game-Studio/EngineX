#pragma once

#include "Renderer.h"

#include <SDL.h>
#include "LevelManager.h"
#include "Player.h"
#include "Config.h"

class RaycastRenderer : public GameRenderer
{
private:
    std::vector<std::vector<std::shared_ptr<Wall>>> _worldMap;

    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    // Textured walls
    SDL_Rect _wallRect = { 0, 0, 1, SCREEN_HEIGHT };

    int renderLoop = 0;

public:
    RaycastRenderer(SDL_Window* pWindow, const char* id);

    void DrawFrame() override;

};