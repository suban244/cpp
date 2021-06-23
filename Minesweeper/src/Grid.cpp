#include "Grid.h"

// easy = 10 x 8, 10, 80 x 80 block
// medium = 20 x 16 , 50, 40 x 40 block
// hard = 25 x 20 , 120 , 32 x 32 block

Grid::Grid(int width, int height) {
  gameHeight = height;
  gameWidth = width;
  isConstructed = false;

  scoreTexture = TextureManager::loadSentence("Score");
  timeTexture = TextureManager::loadSentence("Time");
  generateTexture();
}

void Grid::init(int difficulty) {
  switch (difficulty) {
  case EASY_DIFFICULTY:
    blockWidth = 80;
    widthCount = 10;
    heightCount = 8;
    bombCount = 10;
    break;

  case MEDIUM_DIFFICULTY:
    blockWidth = 40;
    widthCount = 20;
    heightCount = 16;
    bombCount = 50;
    break;

  case HARD_DIFFICULTY:
    blockWidth = 32;
    widthCount = 25;
    heightCount = 20;
    bombCount = 120;
    break;

  default:
    break;
  }

  blocks = new int *[heightCount];
  blockStates = new int *[heightCount];
  for (int i = 0; i < heightCount; i++) {
    blocks[i] = new int[widthCount];
    blockStates[i] = new int[widthCount];
    for (int j = 0; j < widthCount; j++) {
      blocks[i][j] = 0;
      blockStates[i][j] = HIDDEN;
    }
  }

  gridStartPosY = gameHeight / 2 - (blockWidth * heightCount / 2);
  gridStartPosX = gameWidth / 2 - (blockWidth * widthCount / 2);

  flagCount = 0;
}

void Grid::construct(int x, int y) {
  int count = bombCount;
  int i, j;
  std::srand(time(NULL));

  while (count != 0) {
    i = rand() % heightCount;
    j = rand() % widthCount;

    // Why THE FUCK DO i and x not point in the same direction
    if (j >= (x - 2) && j <= (x + 2) && i >= (y - 2) && i <= (y + 2)) {
      // When we are about to place a mine at/around starting position.
      continue;
    }

    if (blocks[i][j] == MINE) {
      continue;
    }
    blocks[i][j] = MINE;

    count--;
  }

  for (int i = 0; i < heightCount; i++) {
    for (int j = 0; j < widthCount; j++) {
      int bombCount = 0;

      if (blocks[i][j] == MINE)
        continue;

      // IDK hard code for everyone (edges and corners)?
      if (i == 0 && j == 0) {
        if (blocks[i + 1][j] == MINE)
          bombCount += 1;
        if (blocks[i][j + 1] == MINE)
          bombCount += 1;
        if (blocks[i + 1][j + 1] == MINE)
          bombCount += 1;

        blocks[i][j] = bombCount;
        continue;
      }
      if (i == heightCount - 1 && j == 0) {
        if (blocks[i - 1][j] == MINE)
          bombCount += 1;
        if (blocks[i][j + 1] == MINE)
          bombCount += 1;
        if (blocks[i - 1][j + 1] == MINE)
          bombCount += 1;

        blocks[i][j] = bombCount;
        continue;
      }
      if (i == 0 && j == widthCount - 1) {
        if (blocks[i + 1][j] == MINE)
          bombCount += 1;
        if (blocks[i][j - 1] == MINE)
          bombCount += 1;
        if (blocks[i + 1][j - 1] == MINE)
          bombCount += 1;

        blocks[i][j] = bombCount;
        continue;
      }
      if (i == heightCount - 1 && j == widthCount - 1) {
        if (blocks[i - 1][j] == MINE)
          bombCount += 1;
        if (blocks[i][j - 1] == MINE)
          bombCount += 1;
        if (blocks[i - 1][j - 1] == MINE)
          bombCount += 1;

        blocks[i][j] = bombCount;
        continue;
      }
      if (i == 0) {
        for (int k = i; k < i + 2; k++) {
          for (int l = j - 1; l < j + 2; l++) {

            if (blocks[k][l] == MINE)
              bombCount += 1;
          }
        }
        blocks[i][j] = bombCount;
        continue;
      }
      if (j == 0) {
        for (int k = i - 1; k < i + 2; k++) {
          for (int l = j; l < j + 2; l++) {

            if (blocks[k][l] == MINE)
              bombCount += 1;
          }
        }
        blocks[i][j] = bombCount;
        continue;
      }
      if (i == heightCount - 1) {
        for (int k = i - 1; k < i + 1; k++) {
          for (int l = j - 1; l < j + 2; l++) {

            if (blocks[k][l] == MINE)
              bombCount += 1;
          }
        }
        blocks[i][j] = bombCount;
        continue;
      }
      if (j == widthCount - 1) {
        for (int k = i - 1; k < i + 2; k++) {
          for (int l = j - 1; l < j + 1; l++) {

            if (blocks[k][l] == MINE)
              bombCount += 1;
          }
        }
        blocks[i][j] = bombCount;
        continue;
      }
      // Loopty Loop for simple ones
      for (int k = i - 1; k < i + 2; k++) {
        for (int l = j - 1; l < j + 2; l++) {

          if (blocks[k][l] == MINE)
            bombCount += 1;
        }
      }
      blocks[i][j] = bombCount;
    }
  }
  isConstructed = true;
  pop(y, x);
}

void Grid::generateTexture() {
  for (int i = 0; i < 10; i++) {
    blockTexture[i] = TextureManager::loadGridValue(i);
    numberTexture[i] = TextureManager::loadNumTexture(i);
  }
  flagTexture = TextureManager::loadTexture("assets/flag.png");
}

void Grid::update() {
  static int count = 0;
  count += 1;
  if (count > 60) {
    count = 0;
    gameTime++;
  }
}
void Grid::render() {

  SDL_Rect tempRect;
  tempRect.w = blockWidth - 2;
  tempRect.h = blockWidth - 2;
  SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 0);
  for (int i = 0; i < heightCount; i++) {
    for (int j = 0; j < widthCount; j++) {
      tempRect.x = gridStartPosX + blockWidth * j;
      tempRect.y = gridStartPosY + blockWidth * i;

      switch (blockStates[i][j]) {
      case HIDDEN:
        SDL_SetRenderDrawColor(Game::renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(Game::renderer, &tempRect);
        break;

      case POPED:
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 0);
        SDL_RenderFillRect(Game::renderer, &tempRect);
        SDL_RenderCopy(Game::renderer, blockTexture[blocks[i][j]], NULL,
                       &tempRect);
        break;
      case FLAGED:
        SDL_SetRenderDrawColor(Game::renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(Game::renderer, &tempRect);
        SDL_RenderCopy(Game::renderer, flagTexture, NULL, &tempRect);
      }
    }
  }

  // For Time and Score
  tempRect.w = gameWidth * 0.05;
  tempRect.h = gameHeight * 0.05;
  tempRect.x = gameWidth * 0.85;
  tempRect.y = gameHeight * 0.1;

  SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 0);
  SDL_RenderCopy(Game::renderer, timeTexture, NULL, &tempRect);

  tempRect.y = gameHeight * 0.2;
  SDL_RenderCopy(Game::renderer, scoreTexture, NULL, &tempRect);

  tempRect.y = gameHeight * 0.15;
  SDL_RenderCopy(Game::renderer, numberTexture[7], NULL, &tempRect);
  /*
  tempRect.x = gameWidth * 0.86;
  SDL_RenderCopy(Game::renderer, numberTexture[(flagCount / 10) % 10], NULL,
                 &tempRect);
  tempRect.x = gameWidth * 0.87;
  SDL_RenderCopy(Game::renderer, numberTexture[flagCount % 10], NULL,
                 &tempRect);
                 */
}

void Grid::handleMouseClick(SDL_Event event) {
  int x = (event.button.x - gridStartPosX) / blockWidth;
  int y = (event.button.y - gridStartPosY) / blockWidth;

  std::cout << x << ", " << y << std::endl;

  if (event.button.button == SDL_BUTTON_LEFT) {
    if (constructed()) {
      // do the popping this.
      if (blockStates[y][x] == HIDDEN)
        pop(y, x);
    } else {
      // Construct
      construct(x, y);
    }
  } else if (event.button.button == SDL_BUTTON_RIGHT) {
    flag(y, x);
  }
}

bool Grid::constructed() { return isConstructed; }
Grid::~Grid() {
  for (int i = 0; i < heightCount; i++) {
    delete[] blocks[i];
  }
}

void Grid::flag(int i, int j) {
  // i is the y coordinate, j is the x coordinate
  switch (blockStates[i][j]) {
  case HIDDEN:
    blockStates[i][j] = FLAGED;
    flagCount++;
    break;
  case FLAGED:
    blockStates[i][j] = HIDDEN;
    flagCount--;
    break;
  default:
    break;
  }
}

void Grid::pop(int i, int j) {
  blockStates[i][j] = POPED;
  if (blocks[i][j] == 0) {
    for (int k = i - 1; k <= i + 1; k++) {
      for (int l = j - 1; l <= j + 1; l++) {
        if (k < 0 || k > heightCount - 1 || l < 0 || l > widthCount - 1) {
          continue;
        } else {
          if (blockStates[k][l] == HIDDEN)
            pop(k, l);
        }
      }
    }
  }
}
