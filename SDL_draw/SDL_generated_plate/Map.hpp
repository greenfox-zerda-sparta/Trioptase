#pragma once
#include <vector>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

class Map {
private:
  GLuint texture;
  std::vector<char*> texture_names;
  double scale_x;
  double scale_y;
  double scale_z;
public:
  Map();
  ~Map();
  void generate_map(int _beg, int repeat, int x, int z, char ax, int pic);
  void draw_square();
  void generate_tile_net(int);
};

