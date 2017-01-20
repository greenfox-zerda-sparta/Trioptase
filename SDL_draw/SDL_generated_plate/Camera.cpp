#include "Camera.hpp"

Camera::Camera() {
}


Camera::~Camera() {
}

void Camera::place_camera() {
  gluLookAt(0, 6, 2, 0, 0, 0, 0, 6, 0); // EYE:0,4,2; CENTER:0,0,0; UP:0,6,0 
}
