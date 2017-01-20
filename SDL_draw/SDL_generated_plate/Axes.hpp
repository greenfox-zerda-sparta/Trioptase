#pragma once
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

class Axes {
public:
  Axes();
  ~Axes();
  void draw_axes();
};

