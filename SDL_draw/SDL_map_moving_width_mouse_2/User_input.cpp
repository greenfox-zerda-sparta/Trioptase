#include "User_input.hpp"

bool User_input::is_inside(SDL_Rect* rect) {
  if (this->mouse_state_x < rect->x) {
    return false;
  }
  else if (this->mouse_state_x > rect->w + rect->x) {
    return false;
  }
  else if (this->mouse_state_y < rect->y) {
    return false;
  }
  else if (this->mouse_state_y > rect->h + rect->y) {
    return false;
  }
  return true;
}

User_input::User_input(int width, int height) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height) {
  this->changing_x = 0;
  this->changing_y = 0;
  this->changing_mouse_x = 0;
  this->changing_mouse_y = 0;
  this->mouse_x = 0;
  this->mouse_y = 0;
  this->step = 1;
}

void User_input::input_handler(bool& running, bool& building_selector, bool& troop_selector, SDL_Rect* temp_rect_building, SDL_Rect* temp_rect_troop) {
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
      this->changing_mouse_x = event.motion.x;
      this->changing_mouse_y = event.motion.y;
      break;
    case SDL_MOUSEBUTTONDOWN:
      if (temp_rect_building != NULL) {
        SDL_GetMouseState(&this->mouse_state_x, &this->mouse_state_y);                
        this->mouse_x = int((float)this->mouse_state_x / 32 / ((float)20 / 30));
        this->mouse_y = int((float)this->mouse_state_y / 32 / ((float)20 / 30));
        //std::cout << mouse_x << std::endl << mouse_y << std::endl;        
        if (is_inside(temp_rect_building)) {
          //std::cout << "inside" << std::endl;
          if (building_selector) {
            building_selector = false;
          }
          else {
            building_selector = true;
          }
          //std::cout << "mouse button down from \"selected\" area" << std::endl;
        }
      }
      /*temporary solution to handle with different type of objects*/
      if (temp_rect_troop != NULL) {
        SDL_GetMouseState(&this->mouse_state_x, &this->mouse_state_y);
        this->mouse_x = int((float)this->mouse_state_x / 32 / ((float)20 / 30));
        this->mouse_y = int((float)this->mouse_state_y / 32 / ((float)20 / 30));             
        if (is_inside(temp_rect_troop)) {
          //std::cout << "inside" << std::endl;
          if (troop_selector) {
            troop_selector = false;
          }
          else {
            troop_selector = true;
          }
          //std::cout << "mouse button down from \"selected\" area" << std::endl;
        }
      }
      
      break;
    case SDL_MOUSEBUTTONUP:      
      if (temp_rect_building != NULL) {
        SDL_GetMouseState(&this->mouse_state_x, &this->mouse_state_y);
        if (is_inside(temp_rect_building)) {
          //std::cout << "mouse button up from \"selected\" area" << std::endl;
        }
      }
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

int User_input::get_changing_mouse_x() {
  return this->changing_mouse_x;
}

int User_input::get_changing_mouse_y() {
  return this->changing_mouse_y;
}

int User_input::get_mouse_x() {
  if (mouse_x < 30) {
    return this->mouse_x;
  }
  return 0;
}

int User_input::get_mouse_y() {
  if (mouse_y < 30) {
    return this->mouse_y;
  }
  return 0;
}

void User_input::set_step(int _value) {
  this->step = _value;
}

User_input::~User_input() {
}
