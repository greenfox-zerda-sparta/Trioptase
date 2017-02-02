#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

class MapNode {
protected:
  string tile_image_path;
  bool click_status = false;
public:
  string get_tile_image_path();
  MapNode();
  //void setpath(string);
  bool get_click_status();
  void set_click_status();
  ~MapNode();
};

