#include "Graphic.hpp"

Graphic::Graphic(int width, int height) : WINDOW_HEIGHT(height), WINDOW_WIDTH(width) {
}

void Graphic::initialization() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

void Graphic::load_picture(std::string file_name) {
  surface = SDL_LoadBMP(file_name.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[file_name] = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
}

void Graphic::draw_picture(std::string file_name, int pos_x, int pos_y, int width, int height, int d_shift_x, int d_shift_y) {
  rect.x = pos_x * d_shift_x;
  rect.y = pos_y * d_shift_y;
  rect.w = width;
  rect.h = height;
  SDL_RenderCopy(renderer, pictures[file_name], NULL, &rect);
}

void Graphic::render_pictures() {
  SDL_RenderPresent(renderer);
}

Graphic::~Graphic() {
  for (std::map<std::string, SDL_Texture*>::iterator it = pictures.begin(); it != pictures.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
}
