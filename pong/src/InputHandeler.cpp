#include "InputHandeler.h"
#define W_LOWER 119
#define A_LOWER 97
#define D_LOWER 100
#define S_LOWER 115

std::map<int, int> DirectionKeyMap{
    {W_LOWER, -1}, {A_LOWER, -1}, {D_LOWER, 1}, {S_LOWER, 1}};

void InputHandeler::handleKeyDown(int keyValue, Paddle *paddle) {
  if (keyValue == W_LOWER || keyValue == S_LOWER) {
    paddle->accleratePaddle(DirectionKeyMap[keyValue]);
  }
}
void InputHandeler::handleKeyUp(int keyValue, Paddle *paddle) {
  if (keyValue == W_LOWER || keyValue == S_LOWER) {
    paddle->releaseAccleration(DirectionKeyMap[keyValue]);
  }
}
