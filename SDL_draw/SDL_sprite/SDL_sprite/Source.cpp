#include "Header.h"

SDL_Texture* LoadTexture(std::string file_name, SDL_Renderer* renderer) {
  SDL_Texture* texture = NULL;
  SDL_Surface* surface = SDL_LoadBMP(file_name.c_str());
  if (surface != NULL) {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
  }
  return texture;
}

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
/*
//additiions for the sprite
  SDL_Renderer* character_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Texture* image = LoadTexture("tojas.bmp", character_renderer);

  SDL_Rect character_position;
  character_position.h = 48;
  character_position.w = 48;
  character_position.x = 0;
  character_position.y = 0;
// here ends the sprite part
*/
  SDL_GL_CreateContext(window);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOVY, ASPECT, Z_NEAR, Z_FAR);
  glEnable(GL_DEPTH_TEST);

  /// SDL event handling

  bool running = true;
  SDL_Event event;

  while (running) {

    //drawer(window);

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
    
  //SDL_RenderClear(character_renderer);
  //SDL_RenderCopy(character_renderer, image, NULL, &character_position);
  //SDL_RenderPresent(character_renderer);
    
  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

