#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <utility>
#include "../Entities/Game_logic.hpp"

class Texture_manager {
private:
  const int WINDOW_WIDTH;
  const int WINDOW_HEIGHT;
  const int PANEL_WIDTH;
  SDL_Texture* texture;
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, std::pair<int, int>> texture_resolution;
  SDL_Rect srcrect; //source rect
  SDL_Rect dstrect; //destination rect
  SDL_Rect actual_rect;
  int temp_last_y;
public:
  Texture_manager(int width, int height, int panel_width);
  bool load(std::string file_name, std::string id, int image_width, int image_height, SDL_Renderer* renderer);  
  void statically(std::string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void dynamically_background(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void dynamically_all_tile(int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void dynamically_one_tile(std::string id, int x, int y, int change_x, int change_y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  SDL_Rect get_actual_rect();
  ~Texture_manager();  
};

