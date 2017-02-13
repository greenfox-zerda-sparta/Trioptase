#include "Troop.hpp"
/*
json Troop::to_json() {
  json j = {
    {"health", health_point},
    {"attack", attack_point},
    {"defense", defense_point},
    {"level", level},
    {"price", price}
  };
  return j;
}*/

Troop::Troop(): ID(++BASE_ID) {
  Game_entity::IMG_PATH = "pic/troop.png";
}

Troop::~Troop() {
}
