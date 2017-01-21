#include "Opengl.hpp"
#include "Camera.hpp"
#include "Axes.hpp"
#include "Map.hpp"

int main(int argc, char* argv[]) {
  Opengl opgl;
  Axes ax;
  Camera cam;
  Map quad_map;
  
  SDL_Event event;
  
  opgl.opengl_init();
  
  cam.place_camera();

  ax.draw_axes();
  quad_map.generate_map(3, 3);
  
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