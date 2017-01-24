#include "Texture_manager.hpp"

Texture_manager::Texture_manager() : WINDOW_WIDTH(0), WINDOW_HEIGHT(0) {

}

Texture_manager::Texture_manager(int width, int height) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height) {
}

bool Texture_manager::load(std::string file_name, std::string id, int image_width, int image_height, SDL_Renderer* renderer) {
  SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
  std::pair<int, int> temp_pair;
  temp_pair.first = image_width;
  temp_pair.second = image_height;

  if (temp_surface == 0) {
    return false;
  }

  this->texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
  SDL_FreeSurface(temp_surface);

  if (this->texture != 0) {
    textures[id] = this->texture;
    texture_resolution[id] = temp_pair;
    return true;
  }
  return false;
}

void Texture_manager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  this->srcrect.x = 0;
  this->srcrect.y = 0;
  this->srcrect.w = dstrect.w = width;
  this->srcrect.h = dstrect.h = height;
  this->dstrect.x = x;
  this->dstrect.y = y;

  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
}

void Texture_manager::draw_frame(std::string id, int x, int y, int width, int height, int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  this->srcrect.x = 0 + change_x;
  this->srcrect.y = 0 + change_y;
  this->srcrect.w = dstrect.w = width;
  this->srcrect.h = dstrect.h = height;
  this->dstrect.x = x;
  this->dstrect.y = y;

  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
}

Texture_manager::~Texture_manager() {
}
