#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <time.h>

#define SORT_SIZE 200
#define RAND_HEIGHT 100
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280
#define CHECK_TIME 2
#define FPS_VALUE 10000

struct sortInfo {
  bool end;
  bool swap;
  int i, j;
};

struct ColorInfo {
  bool color;
  int i, j;
};

sortInfo stepSort(int n[], int length);

int main() {
  int n[SORT_SIZE];
  std::srand(time(NULL));
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    SDL_Window *window = SDL_CreateWindow("Bubble Sort", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                          WINDOW_HEIGHT, 0);

    if (window) {
      std::cout << "Weyy window" << std::endl;
      SDL_Rect *rect[SORT_SIZE], *temp;
      SDL_Renderer *renderer =
          SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      int startX = WINDOW_WIDTH * 0.05;
      int endX = WINDOW_WIDTH * 0.95;
      int startY = WINDOW_HEIGHT * 0.05;
      int endY = WINDOW_HEIGHT * 0.95;
      int block_width = (endX - startX) / SORT_SIZE;
      int block_height_unit = (endY - startY) / RAND_HEIGHT;

      // Initalizing values
      for (int i = 0; i < SORT_SIZE; i++) {
        int num = std::rand() % RAND_HEIGHT + 1;
        n[i] = num;
        rect[i] = new SDL_Rect;

        rect[i]->x = startX + block_width * i + 1;
        rect[i]->w = block_width - 1;
        rect[i]->y = endY - (block_height_unit * num);
        rect[i]->h = block_height_unit * num;
      }

      SDL_Event event;
      bool run = true;

      const int FPS = FPS_VALUE;
      const int frameDelay = 1000 / FPS;

      Uint32 frameStart;
      int frameTime;

      int count = 0;
      ColorInfo colorInfo = {false, 0, 0};
      sortInfo info = {false, false, 0, 0};

      while (run) {
        frameStart = SDL_GetTicks();

        // Handle Events
        SDL_PollEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
          run = false;
          break;
        default:
          break;
        }

        // Update
        if (count % CHECK_TIME == 0) {
          info = stepSort(n, SORT_SIZE);
          if (!info.end) {
            if (info.swap) {
              colorInfo = {true, info.i, info.j};
            } else {
              colorInfo = {true, info.i, info.j};
            }
          } else {
            colorInfo = {false, 0, 0};
          }
        }
        if ((count + CHECK_TIME / 2) % CHECK_TIME == 0) {
          if (info.swap) {

            int x;
            x = rect[info.i]->x;
            rect[info.i]->x = rect[info.j]->x;
            rect[info.j]->x = x;
            temp = rect[info.i];
            rect[info.i] = rect[info.j];
            rect[info.j] = temp;
          }
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // Render stuff
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < SORT_SIZE; i++) {
          SDL_RenderFillRect(renderer, rect[i]);
          if (colorInfo.color) {
            if (i == colorInfo.i) {
              SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
              SDL_RenderFillRect(renderer, rect[i]);
              SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            } else if (i == colorInfo.j) {
              SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
              SDL_RenderFillRect(renderer, rect[i]);
              SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
          }
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
          SDL_Delay(frameDelay - frameTime);
        }

        count++;
      }

      SDL_DestroyWindow(window);
    }
  } else {
    std::cout << "SDL cannot init" << std::endl;
    exit(-1);
  }
}

sortInfo stepSort(int n[], int length) {
  static int i = 0;
  static int j = i;
  static sortInfo info = {false, false, 0, 0};
  int temp;

  if (j >= length) {
    i++;
    j = i;
  }
  if (i >= length) {
    info = {true, false, 0, 0};
    return info;
  }
  if (n[i] > n[j]) {
    temp = n[i];
    n[i] = n[j];
    n[j] = temp;

    info = {false, true, i, j};
  } else {
    info = {false, false, i, j};
  }
  j++;
  return info;
}
