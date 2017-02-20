#include "Window.hpp"

Window::Window(int width, int height) : WINDOW_HEIGHT(height), WINDOW_WIDTH(width) {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

void Window::render_clear() {
  SDL_RenderClear(this->renderer);
}

void Window::render_present() {
  SDL_RenderPresent(this->renderer);
}

SDL_Renderer* Window::get_renderer() {
  return this->renderer;
}

SDL_Window* Window::get_window() {
  return this->window;
}

void Window::close() {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

Window::~Window() {
}
