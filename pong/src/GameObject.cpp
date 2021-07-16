#include "GameObject.h"

GameObject::GameObject(const char *texturesheet, int x, int y) {
  xpos = x;
  ypos = y;

  srcRect.h = srcRect.w = 32;
  srcRect.x = srcRect.y = 0;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;

  objTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject() {}

void GameObject::update() {
  destRect.x = xpos;
  destRect.y = ypos;
}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
