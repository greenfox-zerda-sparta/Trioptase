#include "Axes.hpp"

Axes::Axes() {
}


Axes::~Axes() {
}

void Axes::draw_axes() {
  glBegin(GL_LINE_LOOP);
  glColor3ub(0, 255, 0); // green X
  glVertex3d(100, 0, 0);
  glVertex3d(-100, 0, 0);

  glColor3ub(0, 0, 255); // blue Y
  glVertex3d(0, 100, 0);
  glVertex3d(0, -100, 0);

  glColor3ub(255, 255, 255); // white Z
  glVertex3d(0, 0, 100);
  glVertex3d(0, 0, -100);
  glEnd();
}
