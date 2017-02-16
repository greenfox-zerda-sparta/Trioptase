#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include <string>
#include <map>

class Graphic {
private:
  std::map<std::string, SDL_Texture*> pictures;
  SDL_Surface* surface;
  SDL_Rect rect;
public:
  Graphic();
  void load_picture(std::string file_name, SDL_Renderer* renderer, SDL_Window* window);
  void draw_picture(std::string file_name, SDL_Renderer* renderer, int pos_x, int pos_y, int width, int height, int d_shift_x, int d_shift_y);
  ~Graphic();
};

