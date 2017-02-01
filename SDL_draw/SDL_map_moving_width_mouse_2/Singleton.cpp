#include "Singleton.hpp"
const int MAP_SIZE(30);

Singleton* Singleton::mInstance = NULL;

Singleton::Singleton() {
}

Singleton* Singleton::getInstance() {
  if (mInstance == NULL) {
    mInstance = new Singleton;
  }
  return mInstance;
}

void Singleton::initialize_tile_map() {
  this->tile_map.resize(MAP_SIZE);
  for (int i = 0; i < this->tile_map.size(); i++) {
    this->tile_map[i].resize(MAP_SIZE, 0);
  }
}

void Singleton::clean_tile_map() {
  for (int x = 0; x < MAP_SIZE; x++) {
    for (int y = 0; y < MAP_SIZE; y++) {
      this->tile_map[x][y] = 0;
    }
  }
}

void Singleton::fill_tile_map_with_plus_pattern() {
  for (int x = MAP_SIZE / 8; x < MAP_SIZE * 7 / 8; x++) {
    this->tile_map[x][MAP_SIZE / 2] = 1;
  }

  for (int y = MAP_SIZE / 8; y < MAP_SIZE * 7 / 8; y++) {
    this->tile_map[MAP_SIZE / 2][y] = 1;
  }
}

void Singleton::set_coord_on_tile_map(int x, int y) {
  this->tile_map[x][y] = 1;
}

void Singleton::reset_route() {
  this->route.clear();
}

void Singleton::print_tile_map() {
  if (!this->tile_map.empty()) {
    for (int y = 0; y < this->tile_map.size(); y++) {
      for (int x = 0; x < this->tile_map[y].size(); x++) {
        std::cout << this->tile_map[x][y];
      }
      std::cout << std::endl;
    }
  }
}

void Singleton::print_route() {
  if (!this->route.empty()) {
    for (int i = 0; i < this->route.size(); i++) {
      std::cout << i << ". x = " << this->route[i].first;
      std::cout << ", x = " << this->route[i].second << " |\n";
    }
  }
}

Singleton::~Singleton() {
  delete mInstance;
}

