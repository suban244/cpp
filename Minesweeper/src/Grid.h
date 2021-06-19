#pragma once
#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include <random>
#include <time.h>

#define EASY_DIFFICULTY 1
#define MEDIUM_DIFFICULTY 2
#define HARD_DIFFICULTY 3

#define MINE 9

class Grid {
public:
  Grid(int width, int height);
  ~Grid();

  void init(int difficulty);
  void construct();
  void generateTexture();

  void render();
  void update();

  bool constructed();

  void handleMouseClick(SDL_Event event);

private:
  int **blocks;
  int blockWidth;
  int widthCount;
  int heightCount;
  int bombCount;

  int gameWidth, gameHeight;

  bool isConstructed;
  SDL_Texture *numTexture[10];
  SDL_Texture *texture;
};
