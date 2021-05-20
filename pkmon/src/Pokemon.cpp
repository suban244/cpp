#include "Pokemon.h"

#include <fstream>

// (Name="Josh", dex=4)
Pokemon::Pokemon(std::string Name, int dex) : Entity(Name) {
  std::ifstream dexFile("dex.txt", std::ios::in);

  std::string s;
  // For performance
  s.reserve(RESONABLE_LINE_LENGTH);

  if (!dexFile) {
    std::cout << "Pokemon file could not be opened" << std::endl;
    exit(1);
  }

  std::string type[2];

  for (int i = 0; i < dex; i++) {
    std::getline(dexFile, s);
  }
  dexFile >> species >> type[0] >> type[1];

  std::cout << species << " " << type[0] << " " << type[1] << std::endl;
}
