#pragma once
#include "Game.h"
#include <cstdlib>
#include <ctime>

#define GRID_WIDTH 16
#define ALIVE 1
#define DEAD 0
#define START_RANDOM false

class Grid {
public:
  Grid(int w, int h);
  ~Grid();

  void printGrid();

  void showGrid();
  void updateGrid();
  void flipBlock(int i, int j);

  void makeGrid();

private:
  int height, width;
  int **arr;
  int **new_arr;
};
