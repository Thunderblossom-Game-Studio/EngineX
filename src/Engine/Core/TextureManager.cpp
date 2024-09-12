#include "TextureManager.h"

#include <SDL2/SDL.h>

#include <iostream>

std::vector<SDL_Texture *> TextureManager::_textures;

SDL_Texture* TextureManager::LoadTexture(const char *fileName, SDL_Renderer *pRenderer)
{
    SDL_Surface *pTempSurface = IMG_Load(fileName);
    if(pTempSurface == nullptr)
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        return nullptr;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    if(pTexture == nullptr)
    {
        printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(pTempSurface);

    _textures.push_back(pTexture);

    return pTexture;
}

void TextureManager::DestroyTexture(const char *fileName)
{
    for(int i = 0; i < _textures.size(); i++)
    {
        if(_textures[i] == nullptr)
            continue;

        SDL_DestroyTexture(_textures[i]);
        _textures[i] = nullptr;
    }
}

void TextureManager::Clean()
{
    for(int i = 0; i < _textures.size(); i++)
    {
        if(_textures[i] == nullptr)
            continue;

        SDL_DestroyTexture(_textures[i]);
        _textures[i] = nullptr;
    }

    _textures.clear();
}
