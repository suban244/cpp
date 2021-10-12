#pragma once
#define MAX_VELOCITY 20
#define ACCLERATION_RATE 1
#define MAX_ACCLERATION 4

class Paddle;

class Movement {
public:
  Movement();
  Movement(int xpos, int ypos);
  void update();

  void setPosition(int xpos, int ypos);
  void acclerateX(int direction);
  void acclerateY(int direction);

  void stopX();
  void stopY();

  void bounceX();
  void bounceY();

  void releaseAccleration(int direction);

  friend class Paddle;

private:
  float x, y, vx, vy, ax, ay;
};
