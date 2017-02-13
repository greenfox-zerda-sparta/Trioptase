#include "Building.hpp"



Building::Building(): ID(++BASE_ID) {
  Game_entity::IMG_PATH = "pic/building.png";
}

string Building::to_json() {
  return "";
}

Building::~Building() {
}
