#pragma once
#include "Game.h"
#include "Grid.h"

#define SPACE 32

class InputHandeler {
public:
  static void handleMouseClick(int x, int y, int button, Grid *grid);
  static void handleKeyUp();
  static void handleKeyDown(Game *game, int key);
};
