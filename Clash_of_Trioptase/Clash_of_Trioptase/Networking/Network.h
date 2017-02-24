#pragma once

#include "../Entities/json.hpp"
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <vector>
#include <iostream>

using json = nlohmann::json;
using std::string;
using std::vector;

class Network {
public:
  virtual json receive() = 0;
  virtual void send(json&) = 0;
  string json_to_string(json& _message);

};
