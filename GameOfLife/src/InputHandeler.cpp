#include "InputHandeler.h"

void InputHandeler::handleMouseClick(int x, int y, int button, Grid *grid) {

  int i, j;
  j = x / GRID_WIDTH;
  i = y / GRID_WIDTH;

  grid->flipBlock(i, j);
}

void InputHandeler::handleKeyDown(Game *game, int key) {
  if (key == SPACE) {
    game->changeState();
  }
}
