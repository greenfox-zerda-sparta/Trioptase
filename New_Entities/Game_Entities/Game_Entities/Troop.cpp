#include "Troop.hpp"

string Troop::to_json() {
  return "";
}

Troop::Troop(): ID(++BASE_ID) {
  Game_entity::IMG_PATH = "pic/troop.png";
}

Troop::~Troop() {
}
