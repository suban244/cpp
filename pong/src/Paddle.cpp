#include "Paddle.h"

Paddle::Paddle(const char *texture, int x, int y) : GameObject(texture, x, y) {

  srcRect.h = 20;
  srcRect.w = 3;

  destRect.h = srcRect.h * 5;
  destRect.w = srcRect.w * 3;

  movement = Movement(x, y);

  wallStart = 0;
  wallEnd = GAME_HEIGHT;
}

void Paddle::accleratePaddle(int direction) {
  movement.acclerateY(direction);
  std::cout << xpos << ", " << ypos << std::endl;
}
void Paddle::releaseAccleration(int direction) {
  movement.releaseAccleration(direction);
}

void Paddle::update() {
  movement.update();
  if (wallBounce()) {
    movement.stopY();
  }

  movement.y = movement.y < wallStart ? wallStart : movement.y;
  movement.y =
      (movement.y + destRect.h > wallEnd) ? wallEnd - destRect.h : movement.y;

  xpos = movement.x;
  ypos = movement.y;
  destRect.x = xpos;
  destRect.y = ypos;
}

bool Paddle::wallBounce() {
  if ((ypos) < wallStart || (ypos + destRect.h) > wallEnd)
    return true;

  else
    return false;
}
