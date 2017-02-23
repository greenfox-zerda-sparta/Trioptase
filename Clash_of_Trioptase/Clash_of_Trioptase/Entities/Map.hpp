#pragma once 
#include "MapNode.hpp"
#include "JSON_Serial.hpp"
#include <vector>
#include <iterator>

using std::vector;

static const int MAP_SIZE = 30;

class Map: public JSON_Serial {
public:
  Map();
  void init_map();
  void clear_map();
  json to_json();
  vector<vector<MapNode*>> node_map;
  ~Map();
};

