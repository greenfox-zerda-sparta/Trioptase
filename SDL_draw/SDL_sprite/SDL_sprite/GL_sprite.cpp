#include "GL_sprite.h"

GL_sprite::GL_sprite(double x, double y, double z, double size, int red, int green, int blue) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->size = size;
  this->red = red;
  this->green = green;
  this->blue = blue;
}

void GL_sprite::drawIt() {
  glBegin(GL_QUADS);
  glColor3ub(red, green, blue);
  glVertex3d(x, y, z);
  glVertex3d(x + size, y, z);
  glVertex3d(x + size, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 * size * sin(CAMERA_ANGLE*DEGREE));
  glVertex3d(x, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 * size * sin(CAMERA_ANGLE*DEGREE));
  glEnd();
}

GL_sprite::~GL_sprite() {
}
