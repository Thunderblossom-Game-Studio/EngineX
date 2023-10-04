#include "RaycastRenderer.h"
#include "../Globals/Config.h"
#include "../Globals/GameMap.h"

RaycastRenderer::RaycastRenderer(SDL_Window* pWindow) : GameRenderer(pWindow)
{}

RaycastRenderer::~RaycastRenderer()
{}

void RaycastRenderer::Render()
{
    // // Loop over screen width
    // for (int x = 0; x < SCREEN_WIDTH; x++)
    // {
    //     double camX = 2 * x / (double)SCREEN_WIDTH - 1; // x-coordinate in camera space
    //     double rayDirX = dirX + planeX * camX;
    //     double rayDirY = dirY + planeY * camX;

    //     // which box of the map we're in
    //     int mapX = (int)posX;
    //     int mapY = (int)posY;

    //     // length of ray from current position to next x or y-side
    //     double sideDistX;
    //     double sideDistY;

    // }

}