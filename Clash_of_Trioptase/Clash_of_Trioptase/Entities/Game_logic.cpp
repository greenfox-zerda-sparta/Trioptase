#include "Game_logic.hpp"

using std::ofstream;

Game_logic* Game_logic::game_instance = NULL;

Game_logic::Game_logic() {
  this->map = new Map();
}

Game_logic* Game_logic::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game_logic;
  }
  return game_instance;
}

void Game_logic::delete_game() {
  delete game_instance;
  game_instance = NULL;
}

bool has_obj_key(string key, json obj) {
  for (json::iterator it = obj.begin(); it != obj.end(); ++it) {
    if (*it == key) {
      return true;
    }
  }
  return false;
}

void Game_logic::create_troop_on_map(int first_index, int second_index, json object) {
  Troop* soldier = new Troop;
  soldier->set_ap(object["attack"]);
  soldier->set_dp(object["defense"]);
  soldier->set_hp(object["health"]);
  soldier->set_price(object["price"]);
  map->node_map[first_index][second_index]->set_entity(soldier);
}

void Game_logic::create_building_on_map(int first_index, int second_index, json object) {
  Building* building = new Building;
  building->set_ap(10);
  building->set_dp(10);
  building->set_hp(10);
  building->set_price(10);
  map->node_map[first_index][second_index]->set_entity(building);
}

json Game_logic::read_json_from_file(std::string file_name) {  
  json temp_json;
  std::ifstream my_file(file_name.c_str());
  if (!my_file.is_open()) {
    map->init_map();
    temp_json = map->to_json();
  }
  else {
    my_file >> temp_json;    
  }
  return temp_json;
}

void Game_logic::create_building(int first_index, int second_index) {
  Building* building = new Building;
  building->set_ap(10);
  building->set_dp(10);
  building->set_hp(10);
  building->set_price(10);
  map->node_map[first_index][second_index]->set_entity(building);
}

void Game_logic::create_troop(int first_index, int second_index) {
  Troop* troop = new Troop;
  troop->set_ap(10);
  troop->set_dp(10);
  troop->set_hp(10);
  troop->set_price(10);
  map->node_map[first_index][second_index]->set_entity(troop);
}

void Game_logic::update_map_from_json(json msg_from_server) {
  json empty_json = {"0", nullptr};
  for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
    if (msg_from_server["Map"][i] != empty_json) {
      int first_index = i / MAP_SIZE;
      int second_index = i % MAP_SIZE;
      if (has_obj_key("Troop", msg_from_server["Map"][i][1])) {
        json troop_json = msg_from_server["Map"][i][1][1];
        create_troop_on_map(first_index, second_index, troop_json);
      }
      else if (has_obj_key("Building", msg_from_server["Map"][i][1])) {
        json building_json = msg_from_server["Map"][i][1][1];
        create_building_on_map(first_index, second_index, building_json);
      }
    }
  }
}

void Game_logic::write_json_to_file(json janos, std::string file_name) {
  ofstream file;
  file.open(file_name.c_str());
  file << janos;
  file.close();
}

Game_logic::~Game_logic() {
  for (int i = 0; i < map->node_map.size(); i++) {
    for (int j = 0; j < map->node_map[i].size(); j++) {
      delete map->node_map[i][j];
    }
  }  
  delete map;
  map = NULL;
}
