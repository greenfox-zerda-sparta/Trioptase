#pragma once

#include "json.hpp"
#include <SDL.h>
#include <SDL_net.h>

using json = nlohmann::json;

class Network {
public:
  virtual json receive() = 0;
  virtual void send(json&) = 0;
};

