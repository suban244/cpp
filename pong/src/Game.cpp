#include "Game.h"

Game::Game() {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;

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
}

bool Game::running() { return isRunning; }

void Game::update() { count++; }

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // TODO
  // ball->printMovement();

  SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
  SDL_Event event;

  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;

  case SDL_KEYDOWN:
    // do stuff
    // event.key.keysym.sym gets us the ascii value
    std::cout << event.key.keysym.sym << std::endl;
    break;

  case SDL_KEYUP:
    // do stuff
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
