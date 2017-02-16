#include "recursive_level.hpp"

const int STEPS[30] = { 3,3,4,5,4,4,4,5,5,5,5,5,6,6,6,3,3,4,5,4,4,4,5,5,5,5,5,6,6,6 };
const int COVERABLE = 54;

recursive_level::recursive_level() {
}

void recursive_level::drawer(int x, int y, int covered) {
  if (!Singleton::getInstance()->tile_map[x][y]) {
    Singleton::getInstance()->tile_map[x][y] = 1;
    ++covered;
  }
  if (covered >= COVERABLE) {
    return;
  }
  int stp = rand() % 15;
  int dir = rand() % 4;
  for (int i = 1; i <= STEPS[stp]; ++i) {
    if (dir == 0) { //right
      if (++x > 28) {
        x = 28;
        dir = rand() % 4;
      }
      if (!Singleton::getInstance()->tile_map[x][y]) {
        ++covered;
        Singleton::getInstance()->tile_map[x][y] = 1;
      }
    }
    else if (dir == 1) { //down
      if (++y>28) {
        y = 28;
        dir = rand() % 4;
      }
      if (!Singleton::getInstance()->tile_map[x][y]) {
        ++covered;
        Singleton::getInstance()->tile_map[x][y] = 1;
      }
    }
    else if (dir == 2) { // left
      if (--x<3) {
        x = 3;
        dir = rand() % 4;
      }
      if (!Singleton::getInstance()->tile_map[x][y]) {
        ++covered;
        Singleton::getInstance()->tile_map[x][y] = 1;
      }
    }
    else { // up
      if (--y<3) {
        y = 3;
        dir = rand() % 4;
      }
      if (!Singleton::getInstance()->tile_map[x][y]) {
        ++covered;
        Singleton::getInstance()->tile_map[x][y] = 1;
      }
    }
    if (covered == COVERABLE) {
      return;
    }
  }
  drawer(x, y, covered);
  return;
}

void recursive_level::porgettyu(bool* running, bool* mazing) {  
  std::mutex mtx;
  
  while (running) {
    if (*mazing) {
      mtx.lock();
      Singleton::getInstance()->clean_tile_map();
      this->drawer(3, 3, 0);
      *mazing = false;
      mtx.unlock();
    }
  }
  
}