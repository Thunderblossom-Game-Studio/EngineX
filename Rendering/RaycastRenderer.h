#pragma once

#include "Renderer.h"

class RaycastRenderer : public GameRenderer
{
private:

public:
    RaycastRenderer(SDL_Window* pWindow);
    ~RaycastRenderer();

    void DrawFrame() override;

};