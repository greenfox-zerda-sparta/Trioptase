#include "Texture_manager.hpp"

Texture_manager::Texture_manager() : WINDOW_HEIGHT(0), WINDOW_WIDTH(0) {

}

Texture_manager::Texture_manager(int height, int width) : WINDOW_HEIGHT(height), WINDOW_WIDTH(width) {
}

bool Texture_manager::load(std::string file_name, std::string id, SDL_Renderer* renderer) {
  SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
  if (temp_surface == 0) {
    return false;
  }

  this->texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
  SDL_FreeSurface(temp_surface);

  if (this->texture != 0) {
    textures[id] = this->texture;
    return true;
  }
  return false;
}

void Texture_manager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;
  SDL_RenderCopyEx(renderer, textures[id], &srcRect, &destRect, 0, 0, flip);
}

void Texture_manager::draw_frame(std::string id, int x, int y, int width, int height, int change_y, int change_x, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0 + change_x;
  srcRect.y = 0 + change_y;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(renderer, textures[id], &srcRect, &destRect, 0, 0, flip);
}

Texture_manager::~Texture_manager() {
}
