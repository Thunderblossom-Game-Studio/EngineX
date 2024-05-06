#pragma once
#include <SDL.h>
#include <vector>

class TextureManager
{
private:
    static std::vector<SDL_Texture*> _textures;

public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* pRenderer);
    static void DestroyTexture(const char* fileName);
    static void Clean();
};