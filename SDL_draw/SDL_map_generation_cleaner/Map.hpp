#pragma once
#include <vector>

class Map {
private:
  int map_size;
  std::vector<std::vector<int>> my_map;
public:
  Map(int _map_size);
  int get_my_map_data(int x, int y);
  ~Map();
};

