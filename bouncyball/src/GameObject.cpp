#include "GameObject.h"

GameObject::GameObject(const char *texturesheet, int x, int y) {
  xpos = x;
  ypos = y;

  objTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject() {}

void GameObject::Update() {

  srcRect.h = srcRect.w = 32;
  srcRect.x = srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;
}

void GameObject::Render() {
  SDL_RenderCopy(Game::renderer, this->objTexture, &srcRect, &destRect);
}
