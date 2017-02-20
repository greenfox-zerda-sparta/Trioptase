#include "Game_handler.hpp"

Game_handler::Game_handler() {
  this->window = new Window(WINDOW_WIDTH + PANEL_WIDTH, WINDOW_HEIGHT);
  this->drawer = new Texture_manager(WINDOW_WIDTH, WINDOW_HEIGHT, PANEL_WIDTH);
  this->ui = new User_input(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Game_handler::run() {
  drawer->load("pictures/wallpaper.jpg", "background", 1920, 1080, window->get_renderer());
  drawer->load("pictures/64x64.png", "troop", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "building", 64, 64, window->get_renderer());
  drawer->load("pictures/panel.png", "panel", 260, 640, window->get_renderer());
  drawer->load("pictures/smoke.png", "smoke", 64, 64, window->get_renderer());
  bool building_selector = false;
  bool troop_selector = false;
  bool running = true;
  std::cout << "lefutsz?" << std::endl;
  SDL_Rect* temp_rect_building = NULL;
  SDL_Rect* temp_rect_troop = NULL;

  while (running) {    
    ui->input_handler(running, building_selector, troop_selector, temp_rect_building, temp_rect_troop);    
    
    window->render_clear();

    drawer->draw_frame("background", 0, 0, ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    //drawer->draw_frame_dyn(ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->draw_frame_dyn_pro_tile("smoke", ui->get_changing_x(), ui->get_changing_y(), ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());

    {
      drawer->draw_frame_static("panel", WINDOW_WIDTH, 0, window->get_renderer());
      drawer->draw_frame_static("building", WINDOW_WIDTH + 40, 60, window->get_renderer());
      temp_rect_building = &drawer->get_actual_rect();
      drawer->draw_frame_static("troop", WINDOW_WIDTH + 40, 144 + 190, window->get_renderer());
    }
    window->render_present();
  }  
  window->close();
}

Game_handler::~Game_handler() {
  delete this->window;
  delete this->drawer;
  delete this->ui;
}