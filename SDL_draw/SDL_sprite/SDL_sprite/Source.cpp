#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <glut.h>


const char* WINDOW_TITLE = "sprite on 3D surface";
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int WINDOW_X_POS = 0;
const int WINDOW_Y_POS = 30;

const double FOVY = 70; // field of view in degrees
const double ASPECT = WINDOW_WIDTH / WINDOW_HEIGHT; // aspect of the WINDOW_WIDTH / WINDOW_HEIGHT
const double Z_NEAR = 1; //Specifies the distance from the viewer to the near clipping plane (always positive).
const double Z_FAR = 1000; //Specifies the distance from the viewer to the far clipping plane (always positive).


void drawer(SDL_Window*);


int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN);
  SDL_GL_CreateContext(window);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOVY, ASPECT, Z_NEAR, Z_FAR);
  glEnable(GL_DEPTH_TEST);

  /// SDL event handling

  bool running = true;
  SDL_Event event;

  while (running) {

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
      }
    }

    drawer(window);

  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

void drawer(SDL_Window* window) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1); // EYE:3,4,2; CENTER:0,0,0; UP:0,0,1 

// here i step over the 2 glRotated(angle, double, double); function

  glBegin(GL_QUADS);

  glColor3ub(255, 0, 0);
  glVertex3d(1, 1, 1);
  glVertex3d(1, 1, -1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, 1, 1);

  glEnd();

  glFlush();
  SDL_GL_SwapWindow(window);
}