#pragma once
#include "Entities/Game_logic.hpp"
#include "User_input/User_input.hpp"
#include "Draw/Window.hpp"
#include "Draw/Texture_manager.hpp"
#include <iostream>

static const int WINDOW_WIDTH(640);
static const int WINDOW_HEIGHT(640);
static const int PANEL_WIDTH(260);
//static const int MAP_SIZE(30);

class Game_handler {
private:
  Window* window;
  Texture_manager* drawer;
  User_input* ui;
  std::pair<int, int> selected_coordinates;
public:
  Game_handler();
  void initialization();
  void run();
  void deinitialization();
  ~Game_handler();
};

