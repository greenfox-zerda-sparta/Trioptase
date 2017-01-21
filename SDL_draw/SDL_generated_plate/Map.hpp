#pragma once
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

class Map {
private:
  double scale_x;
  double scale_y;
  double scale_z;
public:
  Map();
  ~Map();
  void generate_map(int _beg, int repeat, int x, int z, char ax);
  void draw_square();
};

