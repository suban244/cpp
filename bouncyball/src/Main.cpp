#include "Game.h"

Game *game = nullptr;

int main() {

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  game = new Game();

  while (game->isRunning()) {
    frameStart = SDL_GetTicks();

    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();
}
