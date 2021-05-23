#include "Grid.h"

Grid::Grid(int w, int h) {
  width = w / GRID_WIDTH;
  height = h / GRID_WIDTH;

  arr = new int *[height];
  for (int i = 0; i < height; i++) {
    arr[i] = new int[width];
  };

  new_arr = new int *[height];
  for (int i = 0; i < height; i++) {
    new_arr[i] = new int[width];
  };

  std::srand(std::time(nullptr));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      arr[i][j] = (START_RANDOM) ? std::rand() % 2 : 0;
    }
  }
  // makeGrid();
}

void Grid::makeGrid() {
  int valueset[5][6] = {{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1},
                        {0, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      arr[i][j] = valueset[i][j];
    }
  }
}

void Grid::printGrid() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl << std::endl;
}

void Grid::showGrid() {
  SDL_Rect rect;
  rect.w = rect.h = GRID_WIDTH - 1;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      rect.x = j * GRID_WIDTH;
      rect.y = i * GRID_WIDTH;
      if (arr[i][j] % 2 != DEAD) {
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(Game::renderer, &rect);
      }
    }
  }
}

void Grid::updateGrid() {
  int sum = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // count live neighbours
      sum = 0;

      if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
        // if Corner or edge  case do this
        if (i == 0 && j == 0) {
          sum = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];

        } else if (i == height - 1 && j == width - 1) {
          sum = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i][j - 1];

        } else if (i == 0 && j == width - 1) {
          sum = arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j];

        } else if (i == height - 1 && j == 0) {
          sum = arr[i - 1][j] + arr[i - 1][j + 1] + arr[i][j + 1];

        } else if (i == 0) {
          sum = arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j - 1] +
                arr[i + 1][j] + arr[i + 1][j + 1];

        } else if (j == 0) {
          sum = arr[i - 1][j] + arr[i + 1][j] + arr[i - 1][j + 1] +
                arr[i][j + 1] + arr[i + 1][j + 1];

        } else if (i == height - 1) {
          sum = arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j - 1] +
                arr[i - 1][j] + arr[i - 1][j + 1];

        } else if (j == width - 1) {
          sum = arr[i - 1][j] + arr[i + 1][j] + arr[i - 1][j - 1] +
                arr[i][j - 1] + arr[i + 1][j - 1];
        }

      } else {
        // If not a edge case
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            sum += arr[k][l];
          }
        }
        sum -= arr[i][j];
        sum = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
              arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j - 1] +
              arr[i + 1][j] + arr[i + 1][j + 1];
      }

      // Do something with the value
      if (arr[i][j] == ALIVE) {
        if (sum == 2 || sum == 3) {
          new_arr[i][j] = ALIVE;
        } else {
          new_arr[i][j] = DEAD;
        }
      } else {
        if (sum == 3) {
          new_arr[i][j] = ALIVE;
        } else
          new_arr[i][j] = DEAD;
      }
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      arr[i][j] = new_arr[i][j];
    }
  }
}

void Grid::flipBlock(int i, int j) {
  if (arr[i][j] == DEAD)
    arr[i][j] = ALIVE;
  else if (arr[i][j] == ALIVE)
    arr[i][j] = DEAD;
}

Grid::~Grid() {
  free(arr);
  free(new_arr);
}
