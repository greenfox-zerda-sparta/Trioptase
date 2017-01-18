
//Compile with : "g++ -o Prog main.cpp `sdl-config --cflags --libs` -lGL -lglut -lGLU" on linux !!!
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

#define WIDTH 640
#define HEIGHT 480

void drawer(SDL_Window* screen);

double angleX, angleZ;

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);
  // SDL_GL_SwapWindow(screen);
  //SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);
  // SDL_EnableKeyRepeat(10, 10);
  //SDL_ShowCursor(false);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)WIDTH / HEIGHT, 1, 1000);
  glEnable(GL_DEPTH_TEST);

  drawer(screen);

  bool running = true;
  SDL_Event event;

  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time, ellapsed_time, start_time;

  while (running) {
    start_time = SDL_GetTicks();
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_RIGHT:
            angleZ += 10;
            break;
          case SDLK_LEFT:
            angleZ -= 10;
            break;
          case SDLK_UP:
            angleX += 10;
            break;
          case SDLK_DOWN:
            angleX -= 10;
            break;
        }
        break;
        case SDL_MOUSEMOTION:
        angleZ = event.motion.x - WIDTH / 2;
        angleX = HEIGHT / 2 - event.motion.y;
        break;
      }
    }
    current_time = SDL_GetTicks();
    ellapsed_time = current_time - last_time;
    last_time = current_time;

    /*This two lines is responsible for auto rotating if you need*/
    //angleZ += 0.05 * ellapsed_time;
    //angleX += 0.05 * ellapsed_time;

    drawer(screen);
    ellapsed_time = SDL_GetTicks() - start_time;
    if (ellapsed_time < 10)
    {
      SDL_Delay(10 - ellapsed_time);
    }
  }

  SDL_Quit();
  return 0;
}

void drawer(SDL_Window* screen)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1); // camera

  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);

  glBegin(GL_QUADS); //Here starts the drawing

/*  glColor3ub(255, 0, 0); //red side
  glVertex3d(1, 1, 1);
  glVertex3d(1, 1, -1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, 1, 1);

  glColor3ub(0, 255, 0); //green side
  glVertex3d(1, -1, 1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, 1, -1);
  glVertex3d(1, 1, 1);

  glColor3ub(0, 0, 255); //blue side
  glVertex3d(-1, -1, 1);
  glVertex3d(-1, -1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, -1, 1);

  glColor3ub(255, 255, 0); //yellow side
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 1);
*/
  glColor3ub(0, 255, 255); //cyan side
  glVertex3d(1, 1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, 1, -1);
/*
  glColor3ub(255, 0, 255); //magenta side
  glVertex3d(1, -1, 1);
  glVertex3d(1, 1, 1);
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, -1, 1);
*/
  glEnd();

  glFlush();
  SDL_GL_SwapWindow(screen);
}