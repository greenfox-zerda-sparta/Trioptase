#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

enum Node_Types {
  EMPTY = 0,
  BUILDING = 1,
  TROOP = 10
};

class MapNode {
protected:
  Node_Types node_type;
  string tile_image_path;
  bool click_status = false;
  int x_coord;
  int y_coord;
public:
  string get_tile_image_path();
  MapNode();
  //void setpath(string);
  bool get_click_status();
  void set_click_status();
  pair<int, int> get_cordinates();
  ~MapNode();
};

