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
  void static_panel();
  bool select_building;
  void select_building_from_panel(bool& clicked);
  void pin_building(bool& clicked);
  bool select_troop_on_panel;
  void select_troop_from_panel(bool& clicked);
  void pin_troop(bool& clicked);
  bool select_enemy_village;
  void show_enemy_village(bool& clicked);
public:
  Game_handler();
  void initialization();
  void run();
  void deinitialization();
  ~Game_handler();
};

