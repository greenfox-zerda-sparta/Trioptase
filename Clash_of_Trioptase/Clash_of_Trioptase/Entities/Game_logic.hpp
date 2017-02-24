#pragma once

#include "Map.hpp"
#include "Troop.hpp"
#include "Building.hpp"
#include <fstream>
#include <string>

class Game_logic {
private:
  Game_logic();
  static Game_logic* game_instance;
  void create_troop_on_map(int, int, json);
  void create_building_on_map(int, int, json);
public:
  json read_json_from_file(std::string file_name);
  void create_building(int first_index, int second_index);
  void create_troop(int first_index, int second_index);
  Map* map = NULL;
  void update_map_from_json(json);
  void write_json_to_file(json, std::string file_name);
  static Game_logic* get_game_instance();
  static void delete_game();
  ~Game_logic();
};

