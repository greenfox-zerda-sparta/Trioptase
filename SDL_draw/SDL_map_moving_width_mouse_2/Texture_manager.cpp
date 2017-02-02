#include "Texture_manager.hpp"

Texture_manager::Texture_manager(int width, int height, int panel_width) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height), PANEL_WIDTH(panel_width) {
  this->temp_last_y = 0;
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
  /*hold the maps view if I navigate to the panel section*/
  if (change_x == WINDOW_WIDTH) {
     temp_last_y = change_y;
  }  
  if (change_x > WINDOW_WIDTH) {    
    change_x = WINDOW_WIDTH;    
    
    change_y = temp_last_y;
  }
  this->srcrect.x = x + change_x * 2;
  this->srcrect.y = y + change_y * 2;
  this->srcrect.w = dstrect.w = this->WINDOW_WIDTH;
  this->srcrect.h = dstrect.h = this->WINDOW_HEIGHT;
  this->dstrect.x = x;
  this->dstrect.y = y;
  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);

  this->actual_rect.x = (x * texture_resolution[id].first - change_x) / 2;
  this->actual_rect.y = (y * texture_resolution[id].second - change_y) / 2;
  this->actual_rect.w = actual_rect.x + texture_resolution[id].first / 2;
  this->actual_rect.h = actual_rect.y + texture_resolution[id].second / 2;
}

void Texture_manager::draw_frame_static(std::string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  this->srcrect.x = 0;
  this->srcrect.y = 0;
  this->srcrect.w = WINDOW_WIDTH + PANEL_WIDTH;
  this->srcrect.h = WINDOW_HEIGHT;  
  this->dstrect.x = x;
  this->dstrect.y = y;
  this->dstrect.w = this->texture_resolution[id].first;
  this->dstrect.h = this->texture_resolution[id].second;
  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);

  this->actual_rect.x = (x);
  this->actual_rect.y = (y);
  this->actual_rect.w = texture_resolution[id].first;
  this->actual_rect.h = texture_resolution[id].second;
}

void Texture_manager::draw_frame_dyn(std::string id, int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip) {  
  /*hold the maps view if I navigate to the panel section*/
  if (change_x == WINDOW_WIDTH) {
    temp_last_y = change_y;
  }
  if (change_x > WINDOW_WIDTH) {
    change_x = WINDOW_WIDTH;

    change_y = temp_last_y;
  }
  for (int i = 2; i < Singleton::getInstance()->tile_map.size()-2; i++) {
    for (int j = 2; j < 28; j++) {
      if (Singleton::getInstance()->tile_map[i][j] == 1) {
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
}

void Texture_manager::draw_frame_dyn_pro_tile(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer * renderer, SDL_RendererFlip flip) {
  /*hold the maps view if I navigate to the panel section*/
  if (change_x == WINDOW_WIDTH) {
    temp_last_y = change_y;
  }
  if (change_x > WINDOW_WIDTH) {
    change_x = WINDOW_WIDTH;

    change_y = temp_last_y;
  }

  this->srcrect.x = 0;
  this->srcrect.y = 0;
  this->srcrect.w = this->WINDOW_WIDTH;
  this->srcrect.h = this->WINDOW_HEIGHT;
  this->dstrect.x = x * texture_resolution[id].first - change_x * 2;
  this->dstrect.y = y * texture_resolution[id].second - change_y * 2;
  this->dstrect.w = texture_resolution[id].first;
  this->dstrect.h = texture_resolution[id].second;

  SDL_RenderCopyEx(renderer, textures[id], &srcrect, &dstrect, 0, 0, flip);

  this->actual_rect.x = (x * texture_resolution[id].first - change_x) / 2;
  this->actual_rect.y = (y * texture_resolution[id].second - change_y) / 2;
  this->actual_rect.w = texture_resolution[id].first / 2;
  this->actual_rect.h = texture_resolution[id].second / 2;
}

SDL_Rect Texture_manager::get_actual_rect() {
  return actual_rect;
}

Texture_manager::~Texture_manager() {
  for (std::map<std::string, SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); ++it) {
    SDL_DestroyTexture(texture);
  }  
}
