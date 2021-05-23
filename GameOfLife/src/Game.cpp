#include "Game.h"
#include "Grid.h"

Game::Game() {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;
Grid *grid = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

    if (window) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    } else {
      std::cout << "Failed to create window" << std::endl;
      exit(-1);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);

  } else {
    std::cout << "Failed to initialize SDL" << std::endl;
    exit(-1);
  }
  isRunning = true;
  grid = new Grid(width, height);
}

bool Game::running() { return isRunning; }

void Game::update() {
  count++;
  if (count % 20 == 0) {
    grid->printGrid();
    grid->updateGrid();
  }
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // TODO
  grid->showGrid();

  SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
  SDL_Event event;

  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;

  default:
    break;
  }
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
