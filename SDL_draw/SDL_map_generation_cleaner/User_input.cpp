#include "User_input.hpp"

User_input::User_input(int start_pos_x, int start_pos_y) {
  this->changing_x = start_pos_x;
  this->changing_y = start_pos_y;
  this->step = 10;
}

void User_input::input_handler(bool& running) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_RIGHT:
        this->changing_x += this->step;
        break;
      case SDLK_LEFT:
        this->changing_x -= this->step;
        break;
      case SDLK_UP:
        this->changing_y -= this->step;
        break;
      case SDLK_DOWN:
        this->changing_y += this->step;
        break;
      case SDLK_ESCAPE:
        running = false;
        break;
      }
      break;
    case SDL_MOUSEMOTION:
      event.motion.x;
      event.motion.y;
      break;
    }
  }
  
}

int User_input::get_changing_x() {
  return this->changing_x;
}

int User_input::get_changing_y() {
  return this->changing_y;
}

User_input::~User_input() {
}
