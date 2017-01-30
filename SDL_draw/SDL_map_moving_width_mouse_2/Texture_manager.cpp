#include "Texture_manager.hpp"

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

void Texture_manager::draw(std::string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  this->srcrect.x = 0;
  this->srcrect.y = 0;
  this->srcrect.w = dstrect.w = this->WINDOW_WIDTH;
  this->srcrect.h = dstrect.h = this->WINDOW_HEIGHT;
  this->dstrect.x = x;
  this->dstrect.y = y;

  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
}

void Texture_manager::draw_frame(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  
  this->srcrect.x = x + change_x * 2;
  this->srcrect.y = y + change_y * 2;
  this->srcrect.w = dstrect.w = this->WINDOW_WIDTH;
  this->srcrect.h = dstrect.h = this->WINDOW_HEIGHT;
  this->dstrect.x = x;
  this->dstrect.y = y;
  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
}

void Texture_manager::draw_frame_dyn(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer * renderer, SDL_RendererFlip flip) {

  for (int i = 2; i < 28; i++) {
    for (int j = 2; j < 28; j++) {
      this->srcrect.x = 0;
      this->srcrect.y = 0;
      this->srcrect.w = this->WINDOW_WIDTH;
      this->srcrect.h = this->WINDOW_HEIGHT;
      this->dstrect.x = i * texture_resolution[id].first - change_x * 2;
      this->dstrect.y = j * texture_resolution[id].second - change_y * 2;
      this->dstrect.w = texture_resolution[id].first;
      this->dstrect.h = texture_resolution[id].second;
      SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
    }
  }
}

void Texture_manager::draw_frame_dyn_pro_tile(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer * renderer, SDL_RendererFlip flip) {
  this->srcrect.x = 0;
  this->srcrect.y = 0;
  this->srcrect.w = this->WINDOW_WIDTH;
  this->srcrect.h = this->WINDOW_HEIGHT;
  this->dstrect.x = x * texture_resolution[id].first - change_x * 2;
  this->dstrect.y = y * texture_resolution[id].second - change_y * 2;
  this->dstrect.w = texture_resolution[id].first;
  this->dstrect.h = texture_resolution[id].second;

  this->actual_rect.x = (x * texture_resolution[id].first - change_x) / 2;
  this->actual_rect.y = (y * texture_resolution[id].second - change_y) / 2;
  this->actual_rect.w = actual_rect.x + texture_resolution[id].first / 2;
  this->actual_rect.h = actual_rect.y + texture_resolution[id].second / 2;
  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);
}

SDL_Rect Texture_manager::get_actual_rect() {
  return actual_rect;
}

Texture_manager::~Texture_manager() {
  for (std::map<std::string, SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); ++it) {
    SDL_DestroyTexture(texture);
  }  
}
