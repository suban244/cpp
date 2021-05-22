#pragma once

#include "Game.h"
#include "GameObject.h"
#include "Movement.h"

class BouncyBall : public GameObject {
public:
  BouncyBall(const char *texturesheet, int x, int y);
  ~BouncyBall();

  void Update();

  void accelerateY(float y);
  void accelerateX(float x);
  void printMovement();

private:
  Movement *movement;
};
