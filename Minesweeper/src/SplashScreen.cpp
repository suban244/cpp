#include "SplashScreen.h"

SplashScreen::SplashScreen(int width, int height) {

  easy.w = medium.w = hard.w = width / 10;
  easy.h = medium.h = hard.h = height / 10;
  easy.y = medium.y = hard.y = height / 2;

  easy.x = width / 2 - width / 5;
  medium.x = width / 2;
  hard.x = width / 2 + width / 5;

  isSelected = false;
  difficulty = MEDIUM_DIFFICULTY;
}

void SplashScreen::render() {
  SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 0);
  SDL_RenderDrawRect(Game::renderer, &easy);
  SDL_RenderDrawRect(Game::renderer, &medium);
  SDL_RenderDrawRect(Game::renderer, &hard);
}

bool SplashScreen::selected() { return isSelected; }
bool SplashScreen::setSelected() {
  this->isSelected = !isSelected;
  return this->isSelected;
}

int SplashScreen::setDifficulty() { return 0; }
int SplashScreen::getDifficulty() { return difficulty; }

int SplashScreen::handleMouseClick(SDL_Event event) {
  int x = event.button.x;
  int y = event.button.y;

  if (x > easy.x && x < (easy.x + easy.w) && y > easy.y &&
      y < (easy.y + easy.w)) {
    return EASY_DIFFICULTY;
  }
  if (x > medium.x && x < (medium.x + medium.w) && y > medium.y &&
      y < (medium.y + medium.w)) {
    return EASY_DIFFICULTY;
  }
  if (x > hard.x && x < (hard.x + hard.w) && y > hard.y &&
      y < (hard.y + hard.w)) {
    return EASY_DIFFICULTY;
  }
  return 0;
}
