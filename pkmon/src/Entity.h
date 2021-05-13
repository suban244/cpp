#pragma once
#include "includes.h"

class Entity
{
protected:
  std::string name;

public:
  Entity();
  Entity(std::string name);
  std::string getName();
};