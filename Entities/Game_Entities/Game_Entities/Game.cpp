#include "Game.hpp"


Game* Game::game_instance = NULL;

Game::Game() : 
  nodes(map_size, vector<MapNode>(map_size, empty_field)), 
  tile_map(map_size, vector<int>(map_size, 0)), 
  path_map(map_size, vector<int>(map_size, 0)) {
}

void Game::fill_tile_map() {
  for (unsigned int i = 0; i < map_size; i++) {
    for (unsigned int j = 0; j < map_size; j++) {
      switch (nodes[i][j].get_node_type()) {
      case 0:
        tile_map[i][j] = 0;
        break;
      case 1:
        tile_map[i][j] = 1;
        break;
      case 10:
        tile_map[i][j] = 10;
        break;
      default:
        tile_map[i][j] = 1;
        break;
      }
    }
  }
}

void Game::fill_path_map() {
  for (unsigned int i = 0; i < map_size; i++) {
    for (unsigned int j = 0; j < map_size; j++) {
      if (nodes[i][j].get_node_type() == 1) {
        path_map[i][j] = 1;
      }
    }
  }
}

Game* Game::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game;
  }
  return game_instance;
}