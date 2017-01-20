#include <Windows.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


// Function to load texture from surface;
SDL_Texture* LoadTexture(std::string file_name, SDL_Renderer* renderer) {
  SDL_Texture* texture = NULL;
  SDL_Surface* surface = SDL_LoadBMP(file_name.c_str());
  if (surface != NULL) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
  }
  return texture;
}

int main(int argc, char* argv[]) {
  //Create variables
  SDL_Window* window = NULL;
  SDL_Texture* image = NULL;
  SDL_Renderer* character_renderer = NULL;
  SDL_Rect character_rect;
  SDL_Rect character_position;
  int frame_width; 
  int frame_height;
  int texture_width;
  int texture_height;
  int FPS = 60;
  int frame_time = 0;
  bool run = true;

  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Alma", 10, 10, 640, 480, 0);
  character_renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
  image = LoadTexture("image.bmp", character_renderer);
  
  SDL_QueryTexture(image,NULL,NULL,&texture_width,&texture_height);

  frame_width = texture_width / 9;
  frame_height = (texture_height / 4);

  character_rect.x = 0;
  character_rect.y = frame_height * 2;
  character_rect.w = frame_width;
  character_rect.h = frame_height;

  // This rect is responsible for the drawn images position on the screeb and size
  character_position.x = 0;
  character_position.y = 0;
  character_position.w = 70;
  character_position.h = 70;

  while(run) {
    //This part is responsible for animating the sprite;
    /*frame_time++;
    if (FPS / frame_time == 5) {
      frame_time = 0;
      character_rect.x += frame_width;
      if (character_rect.x >= texture_width) {
        character_rect.x = 0;
      }
    }*/

    SDL_RenderClear(character_renderer);
    SDL_RenderCopy(character_renderer, image, &character_rect, &character_position);
    SDL_RenderPresent(character_renderer);
  }

  //SDL_Delay(5000);
  
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(image);
  SDL_DestroyRenderer(character_renderer);


  return 0;
}