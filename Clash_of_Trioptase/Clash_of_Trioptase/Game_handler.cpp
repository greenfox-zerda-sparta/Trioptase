#include "Game_handler.hpp"

void Game_handler::static_panel() {
  drawer->statically("panel_grid", WINDOW_WIDTH, 0, window->get_renderer());
  drawer->statically("static_building", WINDOW_WIDTH + 80, 84, window->get_renderer());
  drawer->statically("static_troop", WINDOW_WIDTH + 80, 80 + 190, window->get_renderer());
}

void Game_handler::select_building_from_panel(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 36 && selected_coordinates.second > 2 && selected_coordinates.second < 6) {
    drawer->statically("building_selected", WINDOW_WIDTH + 80, 84, window->get_renderer());
    clicked = true;
  }
}

void Game_handler::pin_building(bool& clicked) {
  if (clicked) {
    if (selected_coordinates.first > 0 && selected_coordinates.first < 29) {
      Game_logic::get_game_instance()->create_building(selected_coordinates.first, selected_coordinates.second);
      this->my_village = Game_logic::get_game_instance()->map->to_json();
      network->communicate->send(my_village);
      clicked = false;
    }
  }
}

void Game_handler::select_troop_from_panel(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 36 && selected_coordinates.second > 11 && selected_coordinates.second < 15) {
    drawer->statically("troop_selected", WINDOW_WIDTH + 80, 80 + 190, window->get_renderer());
    clicked = true;
  }
}

void Game_handler::pin_troop(bool& clicked) {
  if (clicked) {
    if (selected_coordinates.first > 0 && selected_coordinates.first < 29) {
      Game_logic::get_game_instance()->create_troop(selected_coordinates.first, selected_coordinates.second);        
      this->my_village = Game_logic::get_game_instance()->map->to_json();
      network->communicate->send(my_village);      
      clicked = false;
    }
  }
}

void Game_handler::select_enemy_button(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 42 && selected_coordinates.second > 20 && selected_coordinates.second < 23) {
    Game_logic::get_game_instance()->write_json_to_file(Game_logic::get_game_instance()->map->to_json(), "Game_saves/json.json");    
    Game_logic::get_game_instance()->map->clear_map();
    Game_logic::get_game_instance()->map->init_map();    
    Game_logic::get_game_instance()->update_map_from_json(Game_logic::get_game_instance()->read_json_from_file("Multiplayer_data/json.json"));
    clicked = true;
    selected_coordinates.first = 50;
    selected_coordinates.second = 50;
    select_my_village = false;
  }
}

void Game_handler::show_enemy_village(bool& clicked) {
  if (clicked) {    
    drawer->statically("button_selected", WINDOW_WIDTH + 65, 448, window->get_renderer());    
  }
}

void Game_handler::select_my_button(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 42 && selected_coordinates.second > 18 && selected_coordinates.second < 21) {
    if (!first_round) {
      Game_logic::get_game_instance()->write_json_to_file(Game_logic::get_game_instance()->map->to_json(), "Multiplayer_data/json.json");      
    }          
      Game_logic::get_game_instance()->map->clear_map();
      Game_logic::get_game_instance()->map->init_map();
      Game_logic::get_game_instance()->update_map_from_json(Game_logic::get_game_instance()->read_json_from_file("Game_saves/json.json"));      

    first_round = false;
    clicked = true;
    selected_coordinates.first = 50;
    selected_coordinates.second = 50;
    select_enemy_village = false;  
  }
}

void Game_handler::show_my_village(bool& clicked) {
  if (clicked) {    
    drawer->statically("button_selected", WINDOW_WIDTH + 65, 448 - 32, window->get_renderer());    
  }
}

void Game_handler::selection_controller() {
  this->select_building_from_panel(select_building);
  this->pin_building(select_building);
  this->select_troop_from_panel(select_troop_on_panel);
  this->pin_troop(select_troop_on_panel);
  this->select_enemy_button(select_enemy_village);
  this->show_enemy_village(select_enemy_village);
  this->select_my_button(select_my_village);
  this->show_my_village(select_my_village);
}

void Game_handler::background_selector() {
  if (select_my_village) {
    drawer->dynamically_background("background", 0, 0, ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
  }
  if (select_enemy_village) {
    drawer->dynamically_background("background_enemy", 0, 0, ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
  }
}

void Game_handler::network_connection() {
}

void Game_handler::network_update_map() {
  std::mutex mtx;
  mtx.lock();
  
  enemy_village = my_village;//network->communicate->receive();
  std::cout << "update map method" << std::endl;
  mtx.unlock();
}

Game_handler::Game_handler() {
  this->window = new Window(WINDOW_WIDTH + PANEL_WIDTH, WINDOW_HEIGHT);
  this->drawer = new Texture_manager(WINDOW_WIDTH, WINDOW_HEIGHT, PANEL_WIDTH);
  this->ui = new User_input(WINDOW_WIDTH, WINDOW_HEIGHT);
  this->selected_coordinates.first = 33; // my_map botton x if you would like to launch the game with own map
  this->selected_coordinates.second = 19; // my_map botton y if you would like to launch the game with own map
  bool select_building = false;
  first_round = true;
  one = 1;
}

void Game_handler::initialization() {
  drawer->load("pictures/wallpaper.jpg", "background", 1920, 1080, window->get_renderer());
  drawer->load("pictures/wallpaper_enemy.jpg", "background_enemy", 1920, 1080, window->get_renderer());
  drawer->load("pictures/troop.png", "troop", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "building", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "static_building", 32, 32, window->get_renderer());
  drawer->load("pictures/building_selected.png", "building_selected", 32, 32, window->get_renderer());
  drawer->load("pictures/troop.png", "static_troop", 32, 32, window->get_renderer());
  drawer->load("pictures/troop_selected.png", "troop_selected", 32, 32, window->get_renderer());
  drawer->load("pictures/panel.png", "panel", 260, 640, window->get_renderer());
  drawer->load("pictures/panel_grid.png", "panel_grid", 260, 640, window->get_renderer());
  drawer->load("pictures/smoke.png", "smoke", 64, 64, window->get_renderer());
  drawer->load("pictures/button_selected.png", "button_selected", 190, 32, window->get_renderer());

  Game_logic::get_game_instance()->map->init_map();
}

void Game_handler::run() {  
  network = new Broadcast("255.255.255.255", 1234, 1233);
  std::thread network_receive(&Game_handler::network_update_map, &Game_handler());
  network_receive.detach();

  bool running = true;

  while (running) {    
    ui->input_handler(running, this->selected_coordinates);

    window->render_clear();

    this->background_selector();
    drawer->dynamically_all_tile(ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->dynamically_one_tile("smoke", ui->get_changing_x(), ui->get_changing_y(), ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    
    this->static_panel();    
    this->selection_controller();

    window->render_present();
  }

  if (network_receive.joinable()) {
    network_receive.join();
  }

}

void Game_handler::deinitialization() {
  window->close();
}

Game_handler::~Game_handler() {
  delete this->window;
  delete this->drawer;
  delete this->ui;
  delete this->network;
}