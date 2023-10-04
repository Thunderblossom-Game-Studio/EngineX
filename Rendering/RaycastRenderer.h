#pragma once

#include "Renderer.h"

class RaycastRenderer : public GameRenderer
{
private:
    double posX = 22, posY = 12;
    double dirX = -1, dirY = 0;
    double planeX = 0, planeY = 0.66;

    double time = 0;
    double oldTime = 0;

public:
    RaycastRenderer(SDL_Window* pWindow);
    ~RaycastRenderer();

    void Render() override;

};