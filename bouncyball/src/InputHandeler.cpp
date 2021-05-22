#include "InputHandeler.h"
#define W_LOWER 119
#define A_LOWER 97
#define D_LOWER 100
#define S_LOWER 115

std::map<int, int> KeyMap{
    {W_LOWER, -1}, {A_LOWER, -1}, {D_LOWER, 1}, {S_LOWER, 1}};

void InputHandeler::HandleKeyDown(int key, BouncyBall *ball) {

  if (key == W_LOWER || key == S_LOWER) {
    std::cout << "Y" << std::endl;
    ball->accelerateY(KeyMap[key]);
  } else if (key == D_LOWER || key == A_LOWER) {
    std::cout << "X" << std::endl;
    ball->accelerateX(KeyMap[key]);
  }
}

void InputHandeler::HandleKeyUp(int key, BouncyBall *ball) {
  if (key == W_LOWER || key == D_LOWER) {
    ball->accelerateY(0);
  } else if (key == D_LOWER || key == S_LOWER) {
    ball->accelerateX(0);
  }
}
