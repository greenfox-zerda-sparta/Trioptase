#include "Graphic.hpp"

Graphic::Graphic() {
}

void Graphic::load_picture(std::string file_name, SDL_Renderer* renderer, SDL_Window* window) {
  surface = SDL_LoadBMP(file_name.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[file_name] = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
}

void Graphic::draw_picture(std::string file_name, SDL_Renderer* renderer, int pos_x, int pos_y, int width, int height, int d_shift_x, int d_shift_y) {
  rect.x = pos_x * d_shift_x;
  rect.y = pos_y * d_shift_y;
  rect.w = width;
  rect.h = height;
  SDL_RenderCopy(renderer, pictures[file_name], NULL, &rect);
}

Graphic::~Graphic() {
  for (std::map<std::string, SDL_Texture*>::iterator it = pictures.begin(); it != pictures.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
}
