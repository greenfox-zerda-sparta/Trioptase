
//Compile with : "g++ -o Prog main.cpp `sdl-config --cflags --libs` -lGL -lglut -lGLU" on linux !!!
#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <glut.h>
//GLAPI void GLAPIENTRY gluOrtho2D (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
//#include <GL/glut.h>

#define LARGEUR 640
#define LONGUEUR 480

void dessiner(SDL_Window* screen);

double angleX, angleZ;
double x = 1, y = 1, z = 1;

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  //SDL_WM_SetCaption("The 3D Cube of the dead !!!", NULL);
  SDL_Window *screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, /*SDL_WINDOW_FULLSCREEN|*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);
 // SDL_GL_SwapWindow(screen);
  //SDL_SetVideoMode(LARGEUR, LONGUEUR, 32, SDL_OPENGL);
 // SDL_EnableKeyRepeat(10, 10);
  //SDL_ShowCursor(false);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)LARGEUR / LONGUEUR, 1, 1000);
  glEnable(GL_DEPTH_TEST);

  dessiner(screen);
  
  bool continuer = true;
  SDL_Event event;

  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time, ellapsed_time, start_time;

  while (continuer)
  {
    start_time = SDL_GetTicks();
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        continuer = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_RIGHT:
            //angleX += 10;
            //x += 10;
            y += 1;
            z += 1;
          break;
          case SDLK_LEFT:
            //angleZ -= -10;
            //x -= 10;
            y -= 1;
            z -= 1;
          break;
          /*case SDLK_UP:
          posY += 5;
          break;
          case SDLK_DOWN:
          posY -= 5;
          break;*/
        }
        break;
        /*case SDL_MOUSEMOTION:
        posX = event.motion.x-LARGEUR/2;
        posY = LONGUEUR/2-event.motion.y;
        break;*/
      }
    }
    current_time = SDL_GetTicks();
    ellapsed_time = current_time - last_time;
    last_time = current_time;

    angleZ += 0.05 * ellapsed_time;
    angleX += 0.05 * ellapsed_time;

    dessiner(screen);
 
    ellapsed_time = SDL_GetTicks() - start_time;
    if (ellapsed_time < 10)
    {
      SDL_Delay(10 - ellapsed_time);
    }
  }

  SDL_Quit();
  return 0;
}

void dessiner(SDL_Window* screen)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(x, y, z, 0, 0, 0, 0, 0, 1); // Caméra

  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);

  glBegin(GL_QUADS); //Début pour le CUBEEEEE
  
  glColor3ub(255, 0, 0); //face rouge
  glVertex3d(1, 1, 1);
  glVertex3d(1, 1, -1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, 1, 1);

  glColor3ub(0, 255, 0); //face verte
  glVertex3d(1, -1, 1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, 1, -1);
  glVertex3d(1, 1, 1);

  glColor3ub(0, 0, 255); //face bleue
  glVertex3d(-1, -1, 1);
  glVertex3d(-1, -1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, -1, 1);
  
  glColor3ub(255, 255, 0); //face jaune
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 1);
  
  glColor3ub(0, 255, 255); //face cyan
  glVertex3d(1, 1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, 1, -1);
  
  glColor3ub(255, 0, 255); //face magenta
  glVertex3d(1, -1, 1);
  glVertex3d(1, 1, 1);
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, -1, 1);
  
  glEnd();

  glFlush();
  SDL_GL_SwapWindow(screen);
}


/*#include <SDL.h>
#include <SDL_opengl.h>
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
}*/

/*#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

int main(int argc, char* argv[]) {
  SDL_Window *window;
  window = SDL_CreateWindow("SDL2/OpenGL Demo", 50, 50, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);
  glClearColor(0.1, 0.4, 0.1, 0.1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
  SDL_Delay(5000);
  SDL_GLContext SDL_GL_CreateContext(SDL_Window* window);
  SDL_GL_DeleteContext(glcontext);
  return 0;

}*/