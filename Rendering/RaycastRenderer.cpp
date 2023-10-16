#include "RaycastRenderer.h"
#include "../Globals/Config.h"
//#include "../Globals/GameMap.h"
#include "../Level/LevelManager.h"
#include "../GameObjects/Player.h"

#include <SDL2/SDL.h>

RaycastRenderer::RaycastRenderer(SDL_Window* pWindow) : GameRenderer(pWindow)
{}

RaycastRenderer::~RaycastRenderer()
{}

void RaycastRenderer::DrawFrame()
{
    // Cache reference to current main level
    std::shared_ptr<Level> mainLevel = LevelManager::instance().GetLevel("main");

    // Cache reference to player
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(mainLevel->GetPlayer());

    // Clear the screen
    SetDrawColor(0, 0, 0, 255);
    Clear();

    // Draw the floor
    SetDrawColor(0, 0, 255, 255);
    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_RenderFillRect(GetRenderer(), &floorRect);

    // Draw the ceiling
    SetDrawColor(255, 255, 255, 255);
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_RenderFillRect(GetRenderer(), &ceilingRect);

    // Draw the walls
    SetDrawColor(255, 0, 0, 255);
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        // Calculate the ray position and direction
        float cameraX = 2 * x / (float)SCREEN_WIDTH - 1; // x-coordinate in camera space
        float rayDirX = player->GetDirX() + player->GetPlaneX() * cameraX;
        float rayDirY = player->GetDirY() + player->GetPlaneY() * cameraX;

        // Which box of the map we're in
        int mapX = (int)player->GetPosX();
        int mapY = (int)player->GetPosY();

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
            sideDistX = (player->GetPosX() - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0f - player->GetPosX()) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player->GetPosY() - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0f - player->GetPosY()) * deltaDistY;
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
            }
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (side == 0)
        {
            perpWallDist = (mapX - player->GetPosX() + (1 - stepX) / 2) / rayDirX;
        }
        else
        {
            perpWallDist = (mapY - player->GetPosY() + (1 - stepY) / 2) / rayDirY;
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
            break;

        case 2:
            SetDrawColor(0,255,0,255);
            break;

        case 3:
            SetDrawColor(0,0,255,255);
            break;

        case 4:
            SetDrawColor(255,255,255,255);
            break;

        default:
            SetDrawColor(255,255,0,255);
            break;
        }

        // Draw the pixels of the stripe as a vertical line
        SDL_RenderDrawLine(GetRenderer(), x, drawStart, x, drawEnd);

    }

    

}