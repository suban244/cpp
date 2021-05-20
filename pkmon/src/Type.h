#pragma once
#include "Entity.h"

// File format
/*
Name
good[] as in the type attack is good against.
bad[] as in the type attack is bad against.
*/

class Type : public Entity {
 private:
  int id;
  std::string name;
  std::vector<int> good;
  std::vector<int> bad;

 public:
  Type(int id);
  std::vector<int> getGood();
  std::vector<int> getBad();
};
