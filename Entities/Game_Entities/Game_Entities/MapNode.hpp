#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

class MapNode {
protected:
  string tile_image_path;
public:
  string get_tile_image_path();
  MapNode();
  //void setpath(string);
  ~MapNode();
};

