#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

int main(int argc, char* argv[]) {
  SDL_Window *window;
  window = SDL_CreateWindow("SDL2/OpenGL Demo", 50, 50, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
  SDL_Delay(5000);
  SDL_GLContext SDL_GL_CreateContext(SDL_Window* window);
  SDL_GL_DeleteContext(glcontext);
  return 0;

}