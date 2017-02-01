#pragma once
#include <iostream>
#include <string>
#include <vector>

class Singleton {
private:        
  static Singleton* mInstance;        
  Singleton();
public:
  static Singleton* getInstance();
  void print();
  std::vector<std::vector<int>> tile_map;
  int a;
};