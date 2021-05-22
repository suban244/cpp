#pragma once
#include "BouncyBall.h"
#include <array>
#include <map>

class InputHandeler {
public:
  static void HandleKeyDown(int key, BouncyBall *ball);
  static void HandleKeyUp(int key, BouncyBall *ball);
};
