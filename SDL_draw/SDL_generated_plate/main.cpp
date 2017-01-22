#include "Opengl.hpp"
#include "Camera.hpp"
#include "Axes.hpp"
#include "Map.hpp"
#include <iostream>
#define WIDTH 640
#define HEIGHT 480
double angle_x = 0;
double angle_z = 0;

int main(int argc, char* argv[]) {
  Opengl opgl;
  Axes ax;
  Camera cam;
  Map quad_map;
  
  SDL_Event event;
  
  opgl.opengl_init(WIDTH, HEIGHT);
  

  bool running = true;
  int repeat = 1;
  while (running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
          break;
        case SDLK_LEFT:
          break;
        case SDLK_UP:
          repeat++;
          break;
        case SDLK_DOWN:
          repeat--;
          break;
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
        case SDL_MOUSEMOTION:
        angle_z = event.motion.x + WIDTH / 2;
        angle_x = HEIGHT / 2 + event.motion.y;
        break;
      }
    }
    opgl.opengl_sreenbuilder();
    cam.place_camera();
    cam.rotate_camera(angle_x, angle_z);
    ax.draw_axes();
    quad_map.generate_tile_net(repeat);
    ///quad_map.generate_map(-1, repeat, 0, 0, 'x', 0);
    
    opgl.opengl_display();
  }
  
  
  while (running) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      running = false;
    }
    
  }
  SDL_Quit();
  return 0;
}