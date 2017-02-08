#pragma once
#include "JSON_Serial.h"
class Game_entity : public JSON_Serial {
public:
  Game_entity();
  string to_json();
  ~Game_entity();
};

