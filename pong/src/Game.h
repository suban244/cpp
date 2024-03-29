#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#define GAME_HEIGHT 640
#define GAME_WIDTH 800

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

  static SDL_Renderer *renderer;

private:
  SDL_Window *window;
  int count = 0;
  bool isRunning;
};
