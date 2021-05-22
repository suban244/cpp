#include "BouncyBall.h"

BouncyBall::BouncyBall(const char *texturesheet, int x, int y)
    : GameObject(texturesheet, x, y) {
  movement = new Movement(x, y);
  srcRect.h = srcRect.w = 32;
  srcRect.x = srcRect.y = 0;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;
}
BouncyBall::~BouncyBall() { free(movement); }

void BouncyBall::Update() {
  movement->Update();

  destRect.x = movement->getX();
  destRect.y = movement->getY();
}

void BouncyBall::accelerateY(float y) { movement->accelerateY(y); }
void BouncyBall::accelerateX(float x) { movement->accelerateX(x); }

void BouncyBall::printMovement() { movement->printState(); }
