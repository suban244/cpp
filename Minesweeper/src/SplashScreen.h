#pragma once

#include "Game.h"
#include "Grid.h"
#include <SDL2/SDL.h>

class SplashScreen {
public:
  SplashScreen(int width, int height);
  ~SplashScreen();

  void makeGrid();
  void render();

  bool selected();
  bool setSelected();
  int getDifficulty();
  int setDifficulty();

  int handleMouseClick(SDL_Event event);

private:
  SDL_Rect easy, medium, hard;
  int difficulty;
  bool isSelected;
  SDL_Texture *chooseDifficultyTexture;
  int gameWidth, gameHeight;
};
