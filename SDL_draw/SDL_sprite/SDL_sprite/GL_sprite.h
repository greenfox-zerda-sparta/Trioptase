#pragma once

#define PI 3.14159265
#define DEGREE (PI/180)

#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <glut.h>
#include <cmath>

const double CAMERA_ANGLE = 71.56;

class GL_sprite {
public:
  double x;
  double y;
  double z;
  double size;
  int red;
  int green;
  int blue;
public:
  GL_sprite(double x, double y, double z, double size, int red, int green, int blue);
  void drawIt();
  ~GL_sprite();
};

