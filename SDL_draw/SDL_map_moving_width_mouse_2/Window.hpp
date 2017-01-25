#pragma once
#include <SDL.h>

class Window {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;
public:
  Window(int width, int height);
  void render_clear();
  void render_present();
  SDL_Renderer* get_renderer();
  SDL_Window* get_window();
  void close();
  ~Window();
};

