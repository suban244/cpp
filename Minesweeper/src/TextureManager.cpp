#include "TextureManager.h"

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
  SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

SDL_Texture *TextureManager::LoadGridValue(int value) {
  TTF_Init();
  TTF_Font *Sans = TTF_OpenFont("Sans.ttf", 24);
  SDL_Color White = {0, 0, 0, 255};

  char a = value + 48;
  if (value == 9) {
    a = 'M';
  }

  SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, &a, White);
  SDL_Texture *Message =
      SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);

  return Message;
}

SDL_Texture *TextureManager::loadTexture(const char *filename) {
  SDL_Surface *tempSurface = IMG_Load(filename);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

  SDL_FreeSurface(tempSurface);

  return tex;
}
