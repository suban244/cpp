#pragma once
#include "Game.h"
#include <SDL2/SDL_ttf.h>

class TextureManager {
public:
  static SDL_Texture *loadGridValue(int value);
  static SDL_Texture *loadNumTexture(int num);
  static SDL_Texture *loadSentence(const char *sentence);
  static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
  static SDL_Texture *loadTexture(const char *filename);
};
