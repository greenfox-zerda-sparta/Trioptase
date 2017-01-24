#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>

class Texture_manager {
private:
  SDL_Texture* texture;
  std::map<std::string, SDL_Texture*> textures;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;
public:
  Texture_manager();
  Texture_manager(int height, int width);
  bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
  void draw(std::string id, int x, int y, int width, int  height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void draw_frame(std::string id, int x, int y, int width, int  height, int change_y, int change_x, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  ~Texture_manager();
};

