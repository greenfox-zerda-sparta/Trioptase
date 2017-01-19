#include <SDL.h>
#include <SDL_opengl.h>
#include <glut.h>
#include <iostream>

float rgbToGl(float);

int main(int argc, char* argv[]) {
  SDL_Window* window = SDL_CreateWindow("SDL2/OpenGL Demo", 0, 30, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);

  glClearColor(rgbToGl(89), rgbToGl(162), rgbToGl(122), 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
  SDL_Delay(5000);
  SDL_GL_DeleteContext(glcontext);
  SDL_DestroyWindow(window);

  return 0;
}

float rgbToGl(float rgb) {
  return rgb / 255;
}