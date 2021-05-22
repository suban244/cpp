#pragma once
#include <iostream>

class Movement {
public:
  Movement(int x, int y);
  ~Movement();

  void setVelocity(float x, float y);
  void setAccleration(float x, float y);
  void accelerateX(float x);
  void accelerateY(float y);
  void Update();

  int getX();
  int getY();

  void printState();

private:
  float x, y, vx, vy, ax, ay;
};
