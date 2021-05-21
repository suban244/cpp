#pragma once

#include "Game.h"
#include "GameObject.h"

class BouncyBall : public GameObject {
public:
  BouncyBall(const char *texturesheet, int x, int y);
  ~BouncyBall();

  // void Render();

  // void Update();
private:
};
