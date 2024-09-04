#include "RaycastRenderer.h"
#include "Config.h"
#include "DeltaTime.h"

#include <iostream>
#include <SDL2/SDL.h>

RaycastRenderer::RaycastRenderer(SDL_Window *pWindow, const char *id)
        : GameRenderer(pWindow, id)
        {

        }

void RaycastRenderer::DrawFrame() {
    // Clear the screen
    RenderClear();

    // Draw the floor
    SetDrawColor(0, 0, 0, 255);
    SDL_RenderFillRect(_pRenderer, &floorRect);

    // Draw the ceiling
    SetDrawColor(255, 255, 255, 255);
    SDL_RenderFillRect(_pRenderer, &ceilingRect);

    // Store the values of the camera
    Vector2 cameraPos = _pCamera->GetPosition();
    Vector2 cameraDir = _pCamera->GetDirection();
    Vector2 cameraPlane = _pCamera->GetPlane();

    // Store the world map
    _worldMap = LevelManager::instance().GetMap();

    // Verify that the world map is not empty
    if (_worldMap.empty()) {
        std::cout << "World map is empty" << std::endl;
        return;
    }

    // Draw the walls
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray pos and direction
        double cameraX = 2 * x / (double) SCREEN_WIDTH - 1; // x-coordinate in camera space
        Vector2 rayDir = Vector2(cameraDir.X + cameraPlane.X * cameraX, cameraDir.Y + cameraPlane.Y * cameraX);

        // Which box of the map we're in
        int mapX = (int) cameraPos.X;
        int mapY = (int) cameraPos.Y;

        // Length of ray from current position to next x or Y-side
        Vector2 sideDist;

        // Length of ray from one x or Y-side to next x or Y-side
        Vector2 deltaDist = Vector2(std::abs(1 / rayDir.X), std::abs(1 / rayDir.Y));
        double perpWallDist;

        // What direction to step in x or Y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was a NS or a EW wall hit?

        // Calculate step and initial sideDist
        if (rayDir.X < 0) {
            stepX = -1;
            sideDist.X = (cameraPos.X - mapX) * deltaDist.X;
        } else {
            stepX = 1;
            sideDist.X = (mapX + 1.0 - cameraPos.X) * deltaDist.X;
        }

        if (rayDir.Y < 0) {
            stepY = -1;
            sideDist.Y = (cameraPos.Y - mapY) * deltaDist.Y;
        } else {
            stepY = 1;
            sideDist.Y = (mapY + 1.0 - cameraPos.Y) * deltaDist.Y;
        }

        // Perform DDA
        while (hit == 0) {
            // Jump to next map square, OR in x-direction, OR in Y-direction
            if (sideDist.X < sideDist.Y) {
                sideDist.X += deltaDist.X;
                mapX += stepX;
                side = 0;
            } else {
                sideDist.Y += deltaDist.Y;
                mapY += stepY;
                side = 1;
            }

            // Check if ray has hit a wall
            if (_worldMap[mapX][mapY])
                hit = 1;
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (side == 0)
            perpWallDist = (mapX - cameraPos.X + (1 - stepX) / 2) / rayDir.X;
        else
            perpWallDist = (mapY - cameraPos.Y + (1 - stepY) / 2) / rayDir.Y;

        // Calculate height of line to draw on screen
        int lineHeight = (int) (SCREEN_HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;

        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        int color = 255 - (int) (perpWallDist * 10);

        if (color <= 0) {
            color = 0;
        }

        // Choose wall color
        switch (_worldMap[mapX][mapY]->GetColour()) {
            case 1:
                //SetDrawColor(255, 0, 0, 255);
                SetDrawColor(color, 0, 0, 255);
                break;
            case 2:
                //SetDrawColor(0, 255, 0, 255);
                SetDrawColor(0, color, 0, 255);
                break;
            case 3:
                //SetDrawColor(0, 0, 255, 255);
                SetDrawColor(0, 0, color, 255);
                break;
            case 4:
                //SetDrawColor(125, 125, 125, 255);
                color = 125 - (int) (perpWallDist * 5);
                if (color <= 0) {
                    color = 0;
                }
                SetDrawColor(color, color, color, 255);
                break;
            default:
                SetDrawColor(0, 0, 0, 0);
                break;
        }

        // Draw the pixels of the stripe as a vertical line
        SDL_RenderDrawLine(_pRenderer, x, drawStart, x, drawEnd);


    }
}