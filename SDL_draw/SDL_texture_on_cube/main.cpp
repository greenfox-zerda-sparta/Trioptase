#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

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

void drawer(SDL_Window* screen)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1); // camera

  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);

  /*INITIALIZATION OF TEXTURE*/
  GLuint texture;
  SDL_Surface* surf = SDL_LoadBMP("walking_seq.bmp");
  if (surf == NULL) { //If failed, say why and don't continue loading the texture
    printf("Error: \"%s\"\n", SDL_GetError()); return;
  }
  GLenum data_fmt; //Determine the data format of the surface by seeing how SDL arranges a test pixel.  This probably only works --  correctly for little-endian machines.
  Uint8 test = SDL_MapRGB(surf->format, 0xAA, 0xBB, 0xCC) & 0xFF;
  if (test == 0xAA) data_fmt = GL_RGB;
  else if (test == 0xCC) data_fmt = 0x80E0;//GL_BGR;
  else {
    printf("Error: \"Loaded surface was neither RGB or BGR!\""); return;
  }
                      
  glGenTextures(1, &texture);//Generate an array of textures.  We only want one texture (one element array), so trick                      
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, data_fmt, GL_UNSIGNED_BYTE, surf->pixels);
  ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  SDL_FreeSurface(surf); //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
  glBindTexture(GL_TEXTURE_2D, texture); //Tell OpenGL that all subsequent drawing operations should try to use the current 2D texture
  glEnable(GL_TEXTURE_2D);
  /*END OF INITIALZATION TEXTURE*/

  /*DRAWING STARTS HERE*/
  glBegin(GL_QUADS); 

  glTexCoord2f(seq + TextPosX, 1.0f); //All subsequent vertices will have an associated texture coordinate of (1,1)
  glVertex3d(ScaleX * 1, ScaleY * 1, 0);
  
  glTexCoord2f(seq + TextPosX, 0.0f); //All subsequent vertices will have an associated texture coordinate of (1,0)
  glVertex3d(ScaleX * 1, ScaleY * (-1), 0);
  
  glTexCoord2f(0.0f + TextPosX, 0.0f); //All subsequent vertices will have an associated texture coordinate of (0,0)
  glVertex3d(ScaleX * (-1), ScaleY * (-1), 0);
  
  glTexCoord2f(0.0f + TextPosX, 1.0f); //All subsequent vertices will have an associated texture coordinate of (0,1)
  glVertex3d(ScaleX * (-1), ScaleY * 1, 0);
  glEnd();
  /*DRAWING ENDS HERE*/

  glFlush();
  SDL_GL_SwapWindow(screen);
}