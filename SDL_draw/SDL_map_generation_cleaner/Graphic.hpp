#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

class Graphic {
private:
  SDL_Window* window;
  std::map<std::string, SDL_Texture*> pictures;
  SDL_Renderer* renderer;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;
  SDL_Surface* surface;
  SDL_Rect rect;
public:
  Graphic(int, int);
  void initialization();
  void load_picture(std::string file_name);
  void draw_picture(std::string file_name, int pos_x, int pos_y, int width, int height, int d_shift_x, int d_shift_y);
  void render_pictures();
  ~Graphic();
};

