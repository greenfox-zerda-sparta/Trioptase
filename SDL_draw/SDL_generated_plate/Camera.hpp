#pragma once
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

class Camera {
public:
  Camera();
  ~Camera();
  void place_camera();
};

