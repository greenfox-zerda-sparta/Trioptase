#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Singleton {
private:        
  static Singleton* mInstance;        
  Singleton();
public:
  static Singleton* getInstance();
  std::vector<std::vector<int>> tile_map;
  std::vector<std::pair<unsigned short int, unsigned short int>> route;
  void initialize_tile_map();
  void clean_tile_map();
  void fill_tile_map_with_plus_pattern();
  void set_coord_on_tile_map(int x, int y);
  void reset_route(); // You have to reset after walk ot the continous pushback operation will fill it
  void print_tile_map();
  void print_route();
  ~Singleton();
};