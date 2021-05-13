#include "Entity.h"

Entity::Entity()
{
  name = "";
}
Entity::Entity(std::string Name)
{
  name = Name;
}

std::string Entity::getName()
{
  return name;
}