#include "RaycastRenderer.h"
#include "../Globals/Config.h"
#include "../Globals/DeltaTime.h"

#include <iostream>
#include <SDL2/SDL.h>

RaycastRenderer::RaycastRenderer(SDL_Window* pWindow) : GameRenderer(pWindow)
{
}

RaycastRenderer::~RaycastRenderer()
{}

void RaycastRenderer::Init()
{
    // Cache reference to game map
    _mainLevel = LevelManager::instance().GetLevel();

    // Cache reference to player
    _player = _mainLevel->GetPlayer();

    // Cache reference to map
    worldMap = _mainLevel->GetMap();
}

void RaycastRenderer::DrawFrame()
{
    // Clear the screen
    RenderClear();

    // Draw the floor
    SetDrawColor(0, 0, 0, 255);
    SDL_RenderFillRect(_pRenderer, &floorRect);

    // Draw the ceiling
    SetDrawColor(255, 255, 255, 255);
    SDL_RenderFillRect(_pRenderer, &ceilingRect);

    // Draw the walls
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        // Calculate the ray position and direction
        float cameraX = 2 * x / (float)SCREEN_WIDTH - 1; // x-coordinate in camera space
        float rayDirX = _player->GetDirX() + _player->GetPlaneX() * cameraX;
        float rayDirY = _player->GetDirY() + _player->GetPlaneY() * cameraX;

        // Which box of the map we're in
        int mapX = (int)_player->GetPosX();
        int mapY = (int)_player->GetPosY();

        // Length of ray from current position to next x or y-side
        float sideDistX;
        float sideDistY;

        // Length of ray from one x or y-side to next x or y-side
        float deltaDistX = std::abs(1 / rayDirX);
        float deltaDistY = std::abs(1 / rayDirY);
        float perpWallDist;

        // What direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was a NS or a EW wall hit?

        // Calculate step and initial sideDist
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (_player->GetPosX() - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0f - _player->GetPosX()) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (_player->GetPosY() - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0f - _player->GetPosY()) * deltaDistY;
        }

        // Perform DDA
        while (hit == 0)
        {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            // Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0)
            {
                hit = 1;
                //std::cout << "Hit" << std::endl;
            }
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (side == 0)
        {
            perpWallDist = (mapX - _player->GetPosX() + (1 - stepX) / 2) / rayDirX;
        }
        else
        {
            perpWallDist = (mapY - _player->GetPosY() + (1 - stepY) / 2) / rayDirY;
        }

        // Calculate height of line to draw on screen
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;

        if (drawStart < 0)
        {
            drawStart = 0;
        }

        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

        if (drawEnd >= SCREEN_HEIGHT)
        {
            drawEnd = SCREEN_HEIGHT - 1;
        }

        // Choose wall color
        switch (worldMap[mapX][mapY])
        {
        case 1:
            SetDrawColor(255, 0, 0, 255);
            //std::cout << "1" << std::endl;
            break;

        case 2:
            SetDrawColor(0,255,0,255);
            //std::cout << "2" << std::endl;
            break;

        case 3:
            SetDrawColor(0,0,255,255);
            //std::cout << "3" << std::endl;
            break;

        case 4:
            SetDrawColor(120,120,120,255);
            //std::cout << "4" << std::endl;
            break;

        default:
            //std::cout << "Render error" << std::endl;
            break;
        }

        // Draw the pixels of the stripe as a vertical line
        SDL_RenderDrawLine(_pRenderer, x, drawStart, x, drawEnd);
    }
}