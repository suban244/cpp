#pragma once
#include "Game.h"
#include <SDL2/SDL_ttf.h>

class TextureManager {
public:
  static SDL_Texture *LoadGridValue(int value);
  static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};
