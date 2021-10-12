#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Movement.h"

class Paddle : public GameObject {
public:
  Paddle(const char *texture, int x, int y);
  void update();

  void accleratePaddle(int direction);
  void releaseAccleration(int direction);

  bool wallBounce();

private:
  Movement movement;

  int wallStart, wallEnd;
};
