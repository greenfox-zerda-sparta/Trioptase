#include "GL_drawer.h"

const char* WINDOW_TITLE = "sprite on 3D surface";
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int WINDOW_X_POS = 0;
const int WINDOW_Y_POS = 30;

const double FOVY = 70; // field of view in degrees
const double ASPECT = WINDOW_WIDTH / WINDOW_HEIGHT; // aspect of the WINDOW_WIDTH / WINDOW_HEIGHT
const double Z_NEAR = 1; //Specifies the distance from the viewer to the near clipping plane (always positive).
const double Z_FAR = 1000; //Specifies the distance from the viewer to the far clipping plane (always positive).

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

  SDL_GL_CreateContext(window);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOVY, ASPECT, Z_NEAR, Z_FAR);
  glEnable(GL_DEPTH_TEST);

  /// SDL event handling

  bool running = true;
  SDL_Event event;
  GL_drawer drawer(window);
  drawer.setCameraPositions(0, 3, 1);
  double angleZ = 0;
  double angleX = 0;


  while (running) {

    //drawer(window);

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_MOUSEMOTION:
        std::cout << "mouse" << std::endl;
        std::cout << angleX << "|" << angleZ << std::endl;
        angleZ = event.motion.x - WINDOW_WIDTH / 2;
        angleX = WINDOW_HEIGHT / 2 - event.motion.y;
        drawer.rotateCamera();
        drawer.setAngle(angleX / 2, angleZ / 2);
        break;
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        case SDLK_LEFT:
          break;
        case SDLK_RIGHT:
          break;
        case SDLK_UP:
          break;
        case SDLK_DOWN:
          break;
        }
        break;
      }
    }

    drawer.draw();
    
  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

