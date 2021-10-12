#pragma once
#include "Paddle.h"
#include <array>
#include <map>

class InputHandeler {
public:
  static void handleKeyDown(int keyValue, Paddle *paddle);
  static void handleKeyUp(int keyValue, Paddle *paddle);
};
