#include "Map.hpp"
#include "texture_functions.hpp"

Map::Map() {
  this->scale_x = 1;
  this->scale_y = 1;
  this->scale_z = 1;
}

Map::~Map() {
}

void Map::generate_map(int _beg, int repeat, int x, int z, char ax) {
  int beg = _beg;
  int end = beg + 2;

  glBegin(GL_QUAD_STRIP);
  glColor3ub(0, 153, 76);
  for (int j = beg + z; j < end + z; j++) {
    for (int i = beg + x; i < end + x; i++) {
      glVertex3d(double(i), 0, double(j));
    }
  }
  glEnd();
  
  switch (ax) {
  case 'x':
    x++;
    z = 0;
    ax = 'z';
    break;
  case 'z':
    z++;
    x = 0;
    ax = 'd';
    break;
  case 'd':
    x++;
    // z++;
    beg++;
    ax = 'x';
    break;
  }
  repeat--;
  if (repeat < 0) {
    return;
  }
  else {
    generate_map(beg, repeat, x, z, ax);
  }
}

void Map::draw_square() {

  glBegin(GL_QUAD_STRIP);

  glColor3ub(0, 153, 76);
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (0)); /// 0,0
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (1)); /// 0,1
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (0)); /// 1,0
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (1)); /// 1,1

  glEnd();
}
