#pragma once

#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
  GameObject(const char *texturesheet, int x, int y);
  ~GameObject();

  void update();
  void render();

protected:
  int xpos, ypos;
  SDL_Rect srcRect, destRect;
  SDL_Texture *objTexture;
};
