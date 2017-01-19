#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>
#include "texture_functions.hpp"

#define WIDTH 640
#define HEIGHT 480

void drawer(SDL_Window* screen);

double angleX, angleZ;
double ScaleX = 0.1;
double ScaleY = 0.1;
double TextPosX = 0.0;
double TextPosY = 0.0;
double seq = 1.0 / 5;


int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);

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
          ScaleX += 0.1;
          ScaleY += 0.1;
          break;
        case SDLK_DOWN:
          ScaleX -= 0.1;
          ScaleY -= 0.1;
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

    /*texture position with tick*/
    TextPosX += seq * ellapsed_time;
    TextPosY += seq * ellapsed_time;

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

GLuint texture; //texture
GLuint texture2; //texture

void drawer(SDL_Window* screen) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1); // camera

  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);

  texture_init(texture, "pic.bmp");
  texture_deinit(texture);
  texture_init(texture2, "pic1.bmp");
  texture_blind_and_enable(texture);
  /*DRAWING STARTS HERE*/
  glBegin(GL_QUAD_STRIP);

  ///  glColor3ub(0, 255, 255);


  glTexCoord2f(0, 0);
  glVertex3d(ScaleX * (0), ScaleY * (0), 0); /// 0,0
  glTexCoord2f(0, 1);
  glVertex3d(ScaleX * (0), ScaleY * (1), 0); /// 0,1
  glTexCoord2f(1, 0);
  glVertex3d(ScaleX * (1), ScaleY * (0), 0); /// 1,0
  glTexCoord2f(1, 1);
  glVertex3d(ScaleX * (1), ScaleY * (1), 0); /// 1,1
  
  
  
  glTexCoord2f(2, 0);
  glVertex3d(ScaleX * (2), ScaleY * (0), 0); /// 2,0
  glTexCoord2f(2, 1);
  glVertex3d(ScaleX * (2), ScaleY * (1), 0); /// 2,1

  glTexCoord2f(0, 1);
  glVertex3d(ScaleX * (0), ScaleY * (1), 0); /// 0,1
  glTexCoord2f(0, 2);
  glVertex3d(ScaleX * (0), ScaleY * (2), 0); /// 0,2
  glTexCoord2f(1, 1);
  glVertex3d(ScaleX * (1), ScaleY * (1), 0); /// 1,1
  glTexCoord2f(1, 2);
  glVertex3d(ScaleX * (1), ScaleY * (2), 0); /// 1,2

  glTexCoord2f(2, 1);
  glVertex3d(ScaleX * (2), ScaleY * (1), 0); /// 2,1
  glTexCoord2f(2, 2);
  glVertex3d(ScaleX * (2), ScaleY * (2), 0); /// 2,2


  glEnd();

  /*DRAWING ENDS HERE*/

  glFlush();
  SDL_GL_SwapWindow(screen);
}