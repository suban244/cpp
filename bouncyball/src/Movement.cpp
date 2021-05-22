#include "Movement.h"
#define ACCLERATION_PADDING 0.1
#define MAX_VEL 3

Movement::Movement(int x, int y) {
  this->x = x;
  this->y = y;

  this->vx = this->vy = 0;
  this->ax = this->ay = 0;
}

Movement::~Movement() {}

void Movement::setAccleration(float x, float y) {
  this->ax = x;
  this->ay = y;
}

void Movement::setVelocity(float x, float y) {
  this->vx = x;
  this->vy = y;
}

void Movement::accelerateY(float value) { ay = value * ACCLERATION_PADDING; }
void Movement::accelerateX(float value) { ax = value * ACCLERATION_PADDING; }

void Movement::Update() {
  this->x += this->vx;
  this->y += this->vy;

  this->vx += this->ax;
  this->vy += this->ay;

  if (this->vx > MAX_VEL) {
    this->vx = MAX_VEL;
  }
  if (this->vx < -MAX_VEL) {
    this->vx = -MAX_VEL;
  }

  if (this->vy > MAX_VEL) {
    this->vy = MAX_VEL;
  }
  if (this->vy < -MAX_VEL) {
    this->vy = -MAX_VEL;
  }
}

int Movement::getX() { return this->x; }
int Movement::getY() { return this->y; }

void Movement::printState() {
  std::cout << "Velocity: " << this->vx << ", " << this->vy << std::endl;
  std::cout << "Accleration: " << this->ax << ", " << this->ay << std::endl;
}
