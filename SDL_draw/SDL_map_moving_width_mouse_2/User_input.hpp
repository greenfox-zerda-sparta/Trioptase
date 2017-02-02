#pragma once
#include <SDL.h>
#include <iostream>

class User_input {
private:
  SDL_Event event;
  const int WINDOW_WIDTH;
  const int WINDOW_HEIGHT;
  int changing_x;
  int changing_y;
  int changing_mouse_x;
  int changing_mouse_y;
  int step;
  int mouse_state_x;
  int mouse_state_y;
  int mouse_x;
  int mouse_y;
  bool is_inside(SDL_Rect* rect);
public:
  User_input(int width, int height);  
  void input_handler(bool& running, bool& building_selector, bool& troop_selector, SDL_Rect* temp_rect_building, SDL_Rect* temp_rect_troop);
  int get_changing_x();
  int get_changing_y();
  int get_changing_mouse_x();
  int get_changing_mouse_y();
  int get_mouse_x();
  int get_mouse_y();
  void set_step(int _value);
  ~User_input();
};

