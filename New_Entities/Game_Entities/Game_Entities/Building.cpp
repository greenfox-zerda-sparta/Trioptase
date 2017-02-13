#include "Building.hpp"



Building::Building(): ID(++BASE_ID) {
  Game_entity::IMG_PATH = "pic/building.png";
}
/*
json Building::to_json() {
  json j = {
    { "health", health_point },
    { "attack", attack_point },
    { "defense", defense_point },
    { "level", level },
    { "price", price }
  };
  return j;
}*/

Building::~Building() {
}
