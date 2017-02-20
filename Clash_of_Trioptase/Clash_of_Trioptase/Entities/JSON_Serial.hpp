#pragma once
#include <string>
#include "json.hpp"

using std::string;
using json = nlohmann::json;

class JSON_Serial {
public:
  virtual json to_json() = 0;
};