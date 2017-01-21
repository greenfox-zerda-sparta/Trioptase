#include "Opengl.hpp"

Opengl::Opengl() {
}

Opengl::~Opengl() {
}

void Opengl::opengl_init(int width, int height) {
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)width / height, 1, 1000);
  glEnable(GL_DEPTH_TEST);
}

void Opengl::opengl_sreenbuilder() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Opengl::opengl_display() {
  glFlush();
  SDL_GL_SwapWindow(screen);
}
