#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

class User_input {
private:
  SDL_Event event;
  int changing_x;
  int changing_y;
  int step;
public:
  User_input(int start_pos_x, int start_pos_y);
  void input_handler(bool& running);
  int get_changing_x();
  int get_changing_y();
  ~User_input();
};

