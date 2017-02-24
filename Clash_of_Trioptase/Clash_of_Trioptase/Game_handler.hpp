#pragma once
#include "Entities/Game_logic.hpp"
#include "User_input/User_input.hpp"
#include "Draw/Window.hpp"
#include "Draw/Texture_manager.hpp"
#include <thread>
#include <mutex>
#include <iostream>
#include "Networking/Broadcast.h"

static const int WINDOW_WIDTH(640);
static const int WINDOW_HEIGHT(640);
static const int PANEL_WIDTH(260);
//static const int MAP_SIZE(30);

class Game_handler {
private:
  Window* window;
  Broadcast* network = NULL;
  Texture_manager* drawer;
  User_input* ui;
  std::pair<int, int> selected_coordinates;  
  json my_village;
  json enemy_village;
  int one;
  void static_panel();
  bool select_building;
  void select_building_from_panel(bool& clicked);
  void pin_building(bool& clicked);
  bool select_troop_on_panel;
  void select_troop_from_panel(bool& clicked);
  void pin_troop(bool& clicked);
  bool select_enemy_village;
  void select_enemy_button(bool& clicked);
  void show_enemy_village(bool& clicked);
  bool select_my_village;
  void select_my_button(bool& clicked);
  void show_my_village(bool& clicked);
  void selection_controller();
  void background_selector();
  void network_connection();

  bool first_round;
public:
  void network_update_map();
  Game_handler();
  void initialization();
  void run();
  void deinitialization();
  ~Game_handler();
};

