#pragma once
#include <string>

using std::string;

class MapNode {
private:
  string tile_image_path;
public:
  string get_tile_image_path();
  MapNode();
  MapNode(string);
  ~MapNode();
};

