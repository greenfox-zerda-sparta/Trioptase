#define PI 3.14159265

#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <glut.h>
#include <cmath>

const double DEGREE = PI / 180;

const char* WINDOW_TITLE = "sprite on 3D surface";
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int WINDOW_X_POS = 0;
const int WINDOW_Y_POS = 30;

const double FOVY = 70; // field of view in degrees
const double ASPECT = WINDOW_WIDTH / WINDOW_HEIGHT; // aspect of the WINDOW_WIDTH / WINDOW_HEIGHT
const double Z_NEAR = 1; //Specifies the distance from the viewer to the near clipping plane (always positive).
const double Z_FAR = 1000; //Specifies the distance from the viewer to the far clipping plane (always positive).

const double RECTANGLE_Y_CORD = 0;
const double CAMERA_ANGLE = 71.56;

void setColor(int red, int green, int blue) {
  glColor3ub(red, green, blue);
}

void drawFourRectangle() {
  glBegin(GL_QUADS);
  setColor(255, 0, 0);
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

void drawAxis() {
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

void drawPlaceForCharacter(double x, double y, double z, double size, int red, int green, int blue) {
  glBegin(GL_QUADS);
  setColor(red, green, blue);
  glVertex3d(x, y, z);
  glVertex3d(x + size, y, z);
  glVertex3d(x + size, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 * size * sin(CAMERA_ANGLE*DEGREE));
  glVertex3d(x, y + size * cos(CAMERA_ANGLE*DEGREE), z + -1 *size * sin(CAMERA_ANGLE*DEGREE));
  glEnd();
}

void drawer(SDL_Window* window) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //CAMERA SETUP
  //        X, Y, Z
  gluLookAt(//2.5, 0.3, 0,  //eye 0,3,1
            0, 3, 1,
            0, 0, 0,  //center
            0, 10000, 0); // up

  // here i step over the 2 glRotated(angle, double, double); function

  drawAxis();
  drawFourRectangle();

  drawPlaceForCharacter(0, 0, 0, 0.5, 0, 255, 0);
  drawPlaceForCharacter(-1, 0, 0, 0.5, 0, 255, 0);
  drawPlaceForCharacter(0.5, 0, -0.5, 0.5, 255, 255, 0);
  drawPlaceForCharacter(0.5, 0, 0.5, 0.5, 0, 0, 255);


  glFlush();
  SDL_GL_SwapWindow(window);
}