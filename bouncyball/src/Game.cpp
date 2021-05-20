#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

    if (window) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);

  } else {
    std::cout << "Failed to initialize SDL" << std::endl;
    exit(-1);
  }
}

void Game::update() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // TODO

  SDL_RenderPresent(renderer);
}

void Game::clean() {}
