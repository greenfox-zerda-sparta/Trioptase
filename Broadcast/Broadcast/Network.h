#pragma once

#include "json.hpp"
#include <SDL.h>
#include <SDL_net.h>

using json = nlohmann::json;

class Network {
public:
  virtual json receive() = 0;
  virtual void send(json&) = 0;
  string json_to_string(json& _message) {
    vector<uint8_t> temp_vec = json::to_msgpack(_message);
    string text = "";
    for (int i = 0; i < temp_vec.size(); i++) {
      text += temp_vec[i];
    }
    return text;
  }
};

