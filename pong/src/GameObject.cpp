#include "GameObject.h"

GameObject::GameObject(const char *texturesheet, int x, int y) {
  xpos = x;
  ypos = y;

  srcRect.h = srcRect.w = 32;
  srcRect.x = srcRect.y = 0;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;

  destRect.y = destRect.x = 0;

  objTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject() {}

void GameObject::update() {
  destRect.x = xpos - destRect.w / 2;
  destRect.y = ypos - destRect.h / 2;
}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
