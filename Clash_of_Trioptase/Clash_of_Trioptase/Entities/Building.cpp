#include "Building.hpp"



Building::Building() : Game_entity() {
  Game_entity::IMG_PATH = "pic/building.png";
}

json Building::to_json() {
  json j = {
    "Building", {
      { "health", health_point },
      { "attack", attack_point },
      { "defense", defense_point },
      { "level", level },
      { "price", price }
    }
  };
  return j;
}

Building::~Building() {
}
