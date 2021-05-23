#include "Game.h"
#include <cstdlib>
#include <ctime>

#define GRID_WIDTH 16
#define ALIVE 1
#define DEAD 0

class Grid {
public:
  Grid(int w, int h);
  ~Grid();

  void printGrid();

  void showGrid();
  void updateGrid();

  void makeGrid();

private:
  int height, width;
  int **arr;
  int **new_arr;
};
