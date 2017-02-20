#include "Troop.hpp"

json Troop::to_json() {
  json j = {
    "Troop", {
      {"health", health_point},
      {"attack", attack_point},
      {"defense", defense_point},
      {"level", level},
      {"price", price}
    }
  };
  return j;
}

Troop::Troop(): Game_entity() {
  Game_entity::IMG_PATH = "troop";
}

Troop::~Troop() {
}
