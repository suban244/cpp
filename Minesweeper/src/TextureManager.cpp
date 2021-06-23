#include "TextureManager.h"

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
  SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

SDL_Texture *TextureManager::loadGridValue(int value) {
  TTF_Init();
  TTF_Font *Sans = TTF_OpenFont("Sans.ttf", 48);
  SDL_Color White = {0, 0, 0, 255};

  char a = value + 48;
  if (value == 9) {
    a = 'M';
  }

  SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, &a, White);
  SDL_Texture *Message =
      SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);

  SDL_FreeSurface(surfaceMessage);
  return Message;
}
SDL_Texture *TextureManager::loadSentence(const char *sentence) {
  TTF_Init();
  TTF_Font *Sans = TTF_OpenFont("Sans.ttf", 48);
  SDL_Color White = {255, 255, 255, 0};

  SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, sentence, White);
  SDL_Texture *Message =
      SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
  SDL_FreeSurface(surfaceMessage);

  return Message;
}

SDL_Texture *TextureManager::loadTexture(const char *filename) {
  SDL_Surface *tempSurface = IMG_Load(filename);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

  SDL_FreeSurface(tempSurface);

  return tex;
}

SDL_Texture *TextureManager::loadNumTexture(int n) {
  TTF_Init();
  TTF_Font *Sans = TTF_OpenFont("Sans.ttf", 48);
  SDL_Color White = {255, 255, 255, 0};

  // char a[2] = {(char)(n + 48), '\0'};
  char a = n + 48;

  SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, &a, White);
  SDL_Texture *Message =
      SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);

  SDL_FreeSurface(surfaceMessage);
  return Message;
}
