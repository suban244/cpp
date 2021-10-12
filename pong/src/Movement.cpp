#include "Movement.h"

Movement::Movement() { x = y = vx = vy = ax = ay = 0; }

Movement::Movement(int xpos, int ypos) {
  x = xpos;
  y = ypos;
  vx = vy = ax = ay = 0;
}

void Movement::update() {
  x += vx;
  y += vy;
  vx += ax;
  vy += ay;

  vx = (vx > MAX_VELOCITY) ? MAX_VELOCITY : vx;
  vy = (vy > MAX_VELOCITY) ? MAX_VELOCITY : vy;
  vx = (vx < -MAX_VELOCITY) ? -MAX_VELOCITY : vx;
  vy = (vy < -MAX_VELOCITY) ? -MAX_VELOCITY : vy;

  ax = (ax > MAX_ACCLERATION) ? MAX_ACCLERATION : ax;
  ay = (ay > MAX_ACCLERATION) ? MAX_ACCLERATION : ay;
  ax = (ax < -MAX_ACCLERATION) ? -MAX_ACCLERATION : ax;
  ay = (ay < -MAX_ACCLERATION) ? -MAX_ACCLERATION : ay;
}

void Movement::setPosition(int xpos, int ypos) {
  x = xpos;
  y = ypos;
}

void Movement::acclerateX(int direction) { ax = direction * ACCLERATION_RATE; }
void Movement::acclerateY(int direction) { ay = direction * ACCLERATION_RATE; }

void Movement::releaseAccleration(int direction) {
  if (ay > 0 && direction > 0) {
    ay = 0;
  } else if (ay < 0 && direction < 0) {
    ay = 0;
  }
  vy = 0;
}

void Movement::bounceX() {
  ax = -ax;
  vx = -vx;
}
void Movement::bounceY() {
  ay = -ay;
  vy = -vy;
}

void Movement::stopX() {
  vx = 0;
  ax = 0;
}

void Movement::stopY() {
  vy = 0;
  ay = 0;
}
