#pragma once 
#include "MapNode.hpp"
#include "JSON_Serial.hpp"
#include <vector>
#include <iterator>

using std::vector;

const int MAP_SIZE = 30; // for the test min 3

class Map: public JSON_Serial {
public:
  Map();
  json to_json();
  vector<vector<MapNode*>> node_map;
  ~Map();
};

