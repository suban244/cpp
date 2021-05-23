#include "Game.h"

Game *game = nullptr;

int main() {

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  game = new Game();

  game->init("Conway Game of Life ", SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED, 800, 640);

  while (game->running()) {

    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  std::cout << "clean" << std::endl;
  game->clean();
}
