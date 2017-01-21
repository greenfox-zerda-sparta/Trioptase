#include "Camera.hpp"

Camera::Camera() {
}


Camera::~Camera() {
}

void Camera::place_camera() {
  gluLookAt(0, 6, 2, 0, 0, 0, 0, 6, 0); // EYE:0,4,2; CENTER:0,0,0; UP:0,6,0 
}

void Camera::rotate_camera(double angle_x, double angle_z) {
  glRotated(angle_x, 1, 0, 0);
  glRotated(angle_z, 0, 0, 1);
}
