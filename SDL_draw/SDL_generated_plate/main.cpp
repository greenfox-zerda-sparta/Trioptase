#include "Opengl.hpp"
#include "Camera.hpp"
#include "Axes.hpp"
#include "Map.hpp"
#include "texture_functions.hpp"

int main(int argc, char* argv[]) {
  Opengl opgl;
  Axes ax;
  Camera cam;
  
  SDL_Event event;
  
  opgl.opengl_init();
  
  cam.place_camera();

  ax.draw_axes();
  
  opgl.opengl_display();

  bool running = true;
  while (running) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      running = false;
    }
    ax.draw_axes();
  }
  SDL_Quit();
  return 0;
}