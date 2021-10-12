#pragma once
#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {

public:
  static SDL_Texture *LoadTexture(const char *filename);
};
