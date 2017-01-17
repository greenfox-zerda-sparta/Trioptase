#include <SDL.h>
#include <SDL_image.h>  

const int HEIGHT = 240;
const int WIDTH = 320;
const char* FILENAME = "pic.bmp";

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Texture* texture = NULL;
  SDL_Surface* surfaceWithPicture = NULL;
    
  //create a window with the given parameters (window_name, window_heigth, window_width, flag_for_window_type) 
  window = SDL_CreateWindow("Texture drawer", 0, 0, HEIGHT, WIDTH, SDL_WINDOW_FULLSCREEN_DESKTOP);
  
  //create a renderer with the given parameters (SDL_Window, index for renderer driver (-1 for the first one supporting), flag_for_rend_target)
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);

  //creaating the texture with SDL_IMAGE(SDL_Renderer, filename)
  texture = IMG_LoadTexture(renderer, FILENAME);

  int textureWidth = 0;
  int textureHeigth = 0;

  //gets the texture's parameters(SDL_Texture, SDL_Pixel_Format, SDL_Texture_Acces) see in SDL_Texture, and gets the width and the heigth;
  SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeigth);

  //creates a recangular sized virtual box on the screen for...
  SDL_Rect rectangle;
  rectangle.x = WIDTH;
  rectangle.y = HEIGHT;
  rectangle.w = textureWidth;
  rectangle.h = textureHeigth;
  
  //cleares the renderer 
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, &rectangle);
  SDL_RenderPresent(renderer);

  SDL_Delay(5000);
  
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit;

  return 0;
}