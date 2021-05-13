#pragma once
#include "Entity.h"
class Pokemon : public Entity
{
private:
  int dex;
  std::string species;

public:
  Pokemon(std::string Name, int dex);
  std::string getSpecies();
};
