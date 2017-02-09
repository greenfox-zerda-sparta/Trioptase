#pragma once
#include "JSON_Serial.hpp"
class Game_entity : public JSON_Serial {
public:
  Game_entity();
  string IMG_PATH;
  virtual string to_json() = 0;
  virtual ~Game_entity() = 0;
};

