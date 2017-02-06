#pragma once
#include <string>

using std::string;

class JSON_Serial {
public:
  virtual string to_json() = 0;
};