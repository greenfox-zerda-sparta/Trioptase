#include "Map.hpp"
#include "texture_functions.hpp"

Map::Map() {
  this->scale_x = 1;
  this->scale_y = 1;
  this->scale_z = 1;
}

Map::~Map() {
}

void Map::generate_map(int size_x, int size_z) {
  glBegin(GL_QUAD_STRIP);
  glColor3ub(0, 153, 76);

  glVertex3d(scale_x * ((double)0) + size_x, scale_y * (0), scale_z * ((double)0) + size_z);
  glVertex3d(scale_x * ((double)0) + size_x, scale_y * (0), scale_z * ((double)1) + size_z);
  glVertex3d(scale_x * ((double)1) + size_x, scale_y * (0), scale_z * ((double)0) + size_z);
  glVertex3d(scale_x * ((double)1) + size_x, scale_y * (0), scale_z * ((double)1) + size_z);

  glEnd();
  
  size_z--;
  if (size_z < 0) {
    return;
  }
  else {
    generate_map(size_x, size_z);
  }
}

void Map::draw_square() {

  glBegin(GL_QUAD_STRIP);

  
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (0)); /// 0,0
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (1)); /// 0,1
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (0)); /// 1,0
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (1)); /// 1,1

  glEnd();
}
