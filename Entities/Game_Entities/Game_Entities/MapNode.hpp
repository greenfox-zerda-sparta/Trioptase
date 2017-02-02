#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

enum Node_Types {
  EMPTY = 0,
  TROOP = 1,
  BUILDING = 10
};

class MapNode {
protected:
  Node_Types node_type;
  string tile_image_path;
  bool click_status = false;
public:
  string get_tile_image_path();
  MapNode();
  //void setpath(string);
  Node_Types get_node_type();
  void set_node_type();
  bool get_click_status();
  void set_click_status();
  ~MapNode();
};

