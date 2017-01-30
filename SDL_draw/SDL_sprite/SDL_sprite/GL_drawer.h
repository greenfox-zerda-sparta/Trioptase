#pragma once

#define PI 3.14159265
#define DEGREE (PI/180)

#include "GL_sprite.h"
#include <vector>

const double RECTANGLE_Y_CORD = 0;
const double CAMERA_ANGLE = 71.56;

class GL_drawer {
public:
  SDL_Window* window = NULL;
  double camera_x_pos;
  double camera_y_pos;
  double camera_z_pos;
  double angleX;
  double angleZ;
public:
  std::vector<GL_sprite> sprtieVector;
public:
  GL_drawer(SDL_Window*);
  ~GL_drawer();
  void draw();
  void drawAxis();
  void drawRectangle(double start_X_Point, double start_Y_point, double size);
  void drawSprite(double, double, double, double, int, int, int);
  void setUpCamera();
  void setCameraPositions(double, double, double);
  void rotateCamera();
  void setAngle(double, double);
};

