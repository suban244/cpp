#include "SplashScreen.h"

SplashScreen::SplashScreen(int width, int height) {
  gameWidth = width;
  gameHeight = height;

  easy.w = medium.w = hard.w = width / 10;
  easy.h = medium.h = hard.h = height / 10;
  easy.y = medium.y = hard.y = height / 2;

  easy.x = width / 2 - width / 5 - easy.w / 2;
  medium.x = width / 2 - medium.w / 2;
  hard.x = width / 2 + width / 5 - hard.w / 2;

  easyText.w = mediumText.w = hardText.w = width / 15;
  easyText.h = mediumText.h = hardText.h = easy.h / 2;
  easyText.y = mediumText.y = hardText.y = height * 0.5 + easy.h * 0.25;

  easyText.x = easy.x + easy.w * 0.1;
  mediumText.x = medium.x + medium.w * 0.1;
  hardText.x = hard.x + hard.w * 0.1;

  isSelected = false;
  difficulty = MEDIUM_DIFFICULTY;
  chooseDifficultyTexture = TextureManager::loadSentence("Choose Difficulty");
  gameWonTexture = TextureManager::loadSentence("GG! You won");
  gameLostTexture = TextureManager::loadSentence("GG! Nice try");

  type = SPLASH_SCREEN_WELCOME;
  difficultyTexture[0] = TextureManager::loadSentence("Easy");
  difficultyTexture[1] = TextureManager::loadSentence("Medium");
  difficultyTexture[2] = TextureManager::loadSentence("Hard");
}

void SplashScreen::render() {
  SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 0);
  SDL_RenderDrawRect(Game::renderer, &easy);
  SDL_RenderDrawRect(Game::renderer, &medium);
  SDL_RenderDrawRect(Game::renderer, &hard);
  SDL_RenderCopy(Game::renderer, difficultyTexture[0], NULL, &easyText);
  SDL_RenderCopy(Game::renderer, difficultyTexture[1], NULL, &mediumText);
  SDL_RenderCopy(Game::renderer, difficultyTexture[2], NULL, &hardText);

  SDL_Rect tempRect;
  tempRect.w = gameWidth * 0.2;
  tempRect.h = gameHeight * 0.05;
  tempRect.x = gameWidth * 0.4;
  tempRect.y = gameHeight * 0.3;
  if (type == SPLASH_SCREEN_WELCOME)
    SDL_RenderCopy(Game::renderer, chooseDifficultyTexture, NULL, &tempRect);
  else if (type == SPLASH_SCREEN_WON)
    SDL_RenderCopy(Game::renderer, gameWonTexture, NULL, &tempRect);
  else if (type == SPLASH_SCREEN_LOST)
    SDL_RenderCopy(Game::renderer, gameLostTexture, NULL, &tempRect);
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
    return MEDIUM_DIFFICULTY;
  }
  if (x > hard.x && x < (hard.x + hard.w) && y > hard.y &&
      y < (hard.y + hard.w)) {
    return HARD_DIFFICULTY;
  }
  return 0;
}

void SplashScreen::setGameOverScreen(int type) {
  this->type = type;
  isSelected = false;
}
