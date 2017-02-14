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

Troop::Troop() : ID(Game_entity::ID), Game_entity::Game_entity() {
  Game_entity::IMG_PATH = "pic/troop.png";
}

Troop::~Troop() {
}
