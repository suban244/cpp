#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height);
  void update();
  void render();
  bool isRunning() { return running; }
  void clean();

  static SDL_Renderer *renderer;

private:
  SDL_Window *window;
  int count = 0;
  bool running;
};
