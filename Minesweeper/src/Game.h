#pragma once
#include "Grid.h"
#include "SplashScreen.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
public:
  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height);
  void update();
  void render();
  void handleEvents();
  bool running();
  void clean();

  bool started();
  void changeState();
  void setHasStarted(bool);

  void makeGrid();

  static SDL_Renderer *renderer;

private:
  SDL_Window *window;
  int count = 0;
  bool isRunning;
  bool hasStarted;
};
