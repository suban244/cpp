#pragma once

#include "Game.h"
#include "Grid.h"
#include <SDL2/SDL.h>

#define SPLASH_SCREEN_WELCOME 0
#define SPLASH_SCREEN_WON 1
#define SPLASH_SCREEN_LOST 2

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

  void setGameOverScreen(int type);

  int handleMouseClick(SDL_Event event);

private:
  SDL_Rect easy, medium, hard;
  SDL_Rect easyText, mediumText, hardText;
  int difficulty;
  bool isSelected;
  int type;

  SDL_Texture *chooseDifficultyTexture;
  SDL_Texture *gameWonTexture;
  SDL_Texture *gameLostTexture;
  SDL_Texture *difficultyTexture[3];
  int gameWidth, gameHeight;
};
