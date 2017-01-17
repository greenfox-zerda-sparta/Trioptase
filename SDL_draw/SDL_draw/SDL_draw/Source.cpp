#include <SDL.h>
#include <iostream>

using std::cerr;
using std::endl;

const int WINDOW_HEIGHT = 20;
const int WINDOW_WIDTH = 20;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window;
  SDL_Surface* pureSurface;
  SDL_Surface* picture;
  SDL_Surface* picture2;
  
  window = SDL_CreateWindow("title", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
  // SDL_SetWindowPosition(window, 200, 200);
  
  // get the empty window as a surface
  pureSurface = SDL_GetWindowSurface(window);
  
  /// pureSurface = SDL_LoadBMP("lego.bmp");
  picture = SDL_LoadBMP("pic.bmp");
  picture2 = SDL_LoadBMP("lego.bmp");
 
  // copy picture surface to the pureSurface (which is the empty window)
  SDL_BlitSurface(picture2, NULL, pureSurface, NULL);
  SDL_BlitSurface(picture, NULL, pureSurface, NULL);
  

  SDL_FreeSurface(picture);
  SDL_UpdateWindowSurface(window);
      
  SDL_Delay(2000);
  
  SDL_DestroyWindow(window);
  SDL_QUIT;

  return 0;
}