#include "Type.h"

#include <fstream>
Type::Type(int id) {
  std::ifstream typeFile("type.txt", std::ios::in);

  std::string s;
  // For performance
  s.reserve(RESONABLE_LINE_LENGTH);
  if (!typeFile) {
    std::cout << "Type file could not be opened" << std::endl;
    exit(1);
  }
}
