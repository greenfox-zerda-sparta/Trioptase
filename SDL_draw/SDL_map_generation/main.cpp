#include <SDL.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using std::cerr;
using std::endl;

const int WINDOW_HEIGHT = 640;
const int WINDOW_WIDTH = 640;
/*
void level_creator() {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] == 1) {
        context.draw_sprite(floor_pic_path, i * 72, j * 72);
      }
      else {
        draw_sprite(wall_pic_path, i * 72, j * 72);
      }
    }
  }
}
*/
int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window;
  //SDL_Surface* pureSurface;
  std::map<std::string, SDL_Texture*> pictures;
  SDL_Renderer* renderer;
  SDL_Event event;

  window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  std::string pic1 = "pics/grass.bmp";
  std::string pic2 = "pics/academy.bmp";
  std::string pic3 = "pics/tower.bmp";
  std::string pic4 = "pics/building.bmp";
  std::string yoda = "pics/yoda.bmp";
  
  SDL_Surface* result = SDL_LoadBMP(pic1.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic1] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
  
  SDL_Surface* result2 = SDL_LoadBMP(pic2.c_str());
  SDL_SetColorKey(result2, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic2] = SDL_CreateTextureFromSurface(renderer, result2);
  SDL_FreeSurface(result2);

  SDL_Surface* result3 = SDL_LoadBMP(pic3.c_str());
  SDL_SetColorKey(result3, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic3] = SDL_CreateTextureFromSurface(renderer, result3);
  SDL_FreeSurface(result3);

  SDL_Surface* result4 = SDL_LoadBMP(pic4.c_str());
  SDL_SetColorKey(result4, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic4] = SDL_CreateTextureFromSurface(renderer, result4);
  SDL_FreeSurface(result4);

  SDL_Surface* result5 = SDL_LoadBMP(yoda.c_str());
  SDL_SetColorKey(result5, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[yoda] = SDL_CreateTextureFromSurface(renderer, result5);
  SDL_FreeSurface(result5);

  SDL_Rect temp;
  SDL_Rect temp2;

  std::vector<std::vector<int>> my_map;
  my_map.resize(10);
  for (int i = 0; i < my_map.size(); i++) {
    my_map[i].resize(10, 0);
  }
  
  my_map[8][7] = 2;

  my_map[4][3] = 2;
  my_map[7][7] = 1;
  my_map[8][7] = 2;
  my_map[5][5] = 2;
  

  for (int i = 0; i < my_map.size(); i++) {
    for (int j = 0; j < my_map[i].size(); j++) {
      std::cout << my_map[i][j] << ' ';
    }
    std::cout << endl;
  }



  int yoda_pos_x = 64;
  int yoda_pos_y = 64;
  int yoda_h = 64;
  int yoda_w = 64;

  int building_pos_x = 64;
  int building_pos_y = 64;
  int building_h = 128;
  int building_w = 128;

  bool running = true;
  while (running) {

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
          yoda_pos_x+=10;
          break;
        case SDLK_LEFT:
          yoda_pos_x-=10;
          break;
        case SDLK_UP:
          yoda_pos_y-=10;
          break;
        case SDLK_DOWN:
          yoda_pos_y+=10;
          break;
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
      }
    }

    for (int i = 0; i < my_map.size(); i++) {
      for (int j = 0; j < my_map[i].size(); j++) {
        if (my_map[i][j] == 0) {

          temp.x = j * 64;
          temp.y = i * 64;
          temp.w = 64;
          temp.h = 64;
          SDL_RenderCopy(renderer, pictures[pic1], NULL, &temp);
          ///  SDL_RenderPresent(renderer);

        }
        else if (my_map[i][j] == 1) {

          temp.x = j * 64;
          temp.y = i * 64;
          temp.w = 64;
          temp.h = 64;
          SDL_RenderCopy(renderer, pictures[pic2], NULL, &temp);
          /// SDL_RenderPresent(renderer);

        }
        else if (my_map[i][j] == 2) {

          temp.x = j * 64;
          temp.y = i * 64;
          temp.w = 64;
          temp.h = 64;
          SDL_RenderCopy(renderer, pictures[pic3], NULL, &temp);
          ///SDL_RenderPresent(renderer);

        }
      }
    }

    if (yoda_pos_y < building_pos_y + (float)building_h * 0.2) {
      temp2.x = yoda_pos_x;
      temp2.y = yoda_pos_y;
      temp2.w = yoda_w;
      temp2.h = yoda_h;
      SDL_RenderCopy(renderer, pictures[yoda], NULL, &temp2);
    
      temp.x = building_pos_x;
      temp.y = building_pos_y;
      temp.w = building_w;
      temp.h = building_h;
      SDL_RenderCopy(renderer, pictures[pic4], NULL, &temp);


    }
    else {
      temp.x = 64;
      temp.y = 64;
      temp.w = 128;
      temp.h = 128;
      SDL_RenderCopy(renderer, pictures[pic4], NULL, &temp);


      temp2.x = yoda_pos_x;
      temp2.y = yoda_pos_y;
      temp2.w = yoda_w;
      temp2.h = yoda_h;
      SDL_RenderCopy(renderer, pictures[yoda], NULL, &temp2);

    }

    SDL_RenderPresent(renderer);
    
    
  }

  SDL_DestroyTexture(pictures[pic1]);
  SDL_DestroyTexture(pictures[pic2]);
  SDL_DestroyTexture(pictures[pic3]);
  SDL_DestroyTexture(pictures[pic4]);
  SDL_DestroyTexture(pictures[yoda]);

  SDL_RenderClear(renderer);
  SDL_DestroyWindow(window);
  
  SDL_QUIT;

  return 0;
}