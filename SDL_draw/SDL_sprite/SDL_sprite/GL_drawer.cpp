#include "GL_drawer.h"

GL_drawer::GL_drawer(SDL_Window* window) {
  this->window = window;
  if (this->window == NULL) {
    std::cerr << "cannot initialise sdl window" << std::endl;
  }
  this->camera_x_pos = 0;
  this->camera_y_pos = 0;
  this->camera_z_pos = 0;
  this->angleX = 0;
  this->angleZ = 0;
}

void GL_drawer::draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  setUpCamera();
  // here i step over the 2 glRotated(angle, double, double); function
  // these are for camera movement...

  drawAxis();
  drawFourRectangle();

  drawSprite(0, 0, 0, 0.5, 0, 255, 0);
  drawSprite(-1, 0, 0, 0.5, 0, 255, 0);
  drawSprite(0.5, 0, -0.5, 0.5, 255, 255, 0);
  drawSprite(0.5, 0, 0.5, 0.5, 0, 0, 255);


  glFlush();
  SDL_GL_SwapWindow(window);
}

void GL_drawer::drawAxis() {
  glBegin(GL_LINE_LOOP);
  glColor3ub(0, 255, 0); // green X
  glVertex3d(100, 0, 0);
  glVertex3d(-100, 0, 0);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3ub(255, 255, 255); // white Z
  glVertex3d(0, 0, 100);
  glVertex3d(0, 0, -100);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3ub(0, 0, 255); // blue Y
  glVertex3d(0, 100, 0);
  glVertex3d(0, 0, 0);
  glEnd();
}

void GL_drawer::drawFourRectangle() {
  glBegin(GL_QUADS);
  glColor3ub(255, 0, 0);
  //first
  glVertex3d(0, -RECTANGLE_Y_CORD, 0);
  glVertex3d(1, -RECTANGLE_Y_CORD, 0);
  glVertex3d(1, -RECTANGLE_Y_CORD, 1);
  glVertex3d(0, -RECTANGLE_Y_CORD, 1);
  //second
  glVertex3d(-1, RECTANGLE_Y_CORD, 0);
  glVertex3d(0, RECTANGLE_Y_CORD, 0);
  glVertex3d(0, RECTANGLE_Y_CORD, 1);
  glVertex3d(-1, RECTANGLE_Y_CORD, 1);
  //third
  glVertex3d(-1, RECTANGLE_Y_CORD, -1);
  glVertex3d(0, RECTANGLE_Y_CORD, -1);
  glVertex3d(0, RECTANGLE_Y_CORD, 0);
  glVertex3d(-1, RECTANGLE_Y_CORD, 0);
  //fourth
  glVertex3d(0, RECTANGLE_Y_CORD, -1);
  glVertex3d(1, RECTANGLE_Y_CORD, -1);
  glVertex3d(1, RECTANGLE_Y_CORD, 0);
  glVertex3d(0, RECTANGLE_Y_CORD, 0);
  glEnd();
}

void GL_drawer::drawSprite(double x, double y, double z, double size, int red, int green, int blue) {
  glBegin(GL_QUADS);
  glColor3ub(red, green, blue);
  glVertex3d(x, y, z);
  glVertex3d(x + size, y, z);
  glVertex3d(x + size, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 * size * sin(CAMERA_ANGLE*DEGREE));
  glVertex3d(x, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 * size * sin(CAMERA_ANGLE*DEGREE));
  glEnd();
}

void GL_drawer::setUpCamera() {
  gluLookAt(
    camera_x_pos, camera_y_pos, camera_y_pos,
    0, 0, 0,
    0, 10000, 0);
}

void GL_drawer::setCameraPositions(double x, double y, double z) {
  this->camera_x_pos = x;
  this->camera_y_pos = y;
  this->camera_z_pos = z;
}

void GL_drawer::rotateCamera() {
  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);
}

void GL_drawer::setAngle(double x_angle, double z_angle) {
  this->angleX = x_angle;
  this->angleZ = z_angle;
}

GL_drawer::~GL_drawer() {
}
