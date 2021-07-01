#include "Game.h"

Game::Game() {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;
SplashScreen *splashScreen = nullptr;
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
  if (TTF_Init() == -1) {
    std::cout << "Failed to initallize ttf" << std::endl;
    exit(-1);
  }

  isRunning = true;
  hasStarted = false;

  splashScreen = new SplashScreen(width, height);
  grid = new Grid(width, height);
}

bool Game::running() { return isRunning; }
bool Game::started() { return hasStarted; }

void Game::update() {
  count++;
  if (hasStarted) {
    // Show the Game
    grid->update();
    if (grid->changeToEndScreen()) {
      hasStarted = false;
      int state = grid->getGameOverState();
      splashScreen->setGameOverScreen(state);
    }
  } else {
    // The menu
    if (splashScreen->selected()) {
      hasStarted = true;
    }
  }
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // TODO
  if (!started()) {
    splashScreen->render();
  } else {
    grid->render();
  }

  SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
  SDL_Event event;

  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_MOUSEBUTTONDOWN:
    if (!hasStarted) {
      // SplashScreen handles the input
      int success = splashScreen->handleMouseClick(event);
      if (success) {
        if (success == 1 || success == 2 || success == 3) {
          grid->init(success);
          hasStarted = true;
        }
      }
    } else {
      // Grid handles the input
      grid->handleMouseClick(event);
    }
    break;

  case SDL_MOUSEBUTTONUP:
    break;

  default:
    break;
  }
}

void Game::changeState() { this->hasStarted = !hasStarted; }

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  TTF_Quit();
}
