#define CATCH_CONFIG_MAIN
#include "Window.hpp"
#include "Graphic.hpp"
#include "User_input.hpp"
#include "Map.hpp"
#include "Texture_manager.hpp"
#include "Path_finder.hpp"
#include "Troop.hpp"

const int WINDOW_WIDTH(640);
const int WINDOW_HEIGHT(640);
const int MAP_SIZE(30);
const int PANEL_WIDTH(260);

#ifdef CATCH_CONFIG_MAIN

int ticker(int steps); //map size -4 is recommended but it must be adjusted

int main(int argc, char* argv[]) {

  Window win(WINDOW_WIDTH + PANEL_WIDTH, WINDOW_HEIGHT);

  User_input input(WINDOW_WIDTH, WINDOW_HEIGHT);

  Texture_manager text_man(WINDOW_WIDTH, WINDOW_HEIGHT, PANEL_WIDTH);
  
  Path_finder pf;
  Singleton::getInstance()->initialize_tile_map();

  std::pair<int, int> start_pos = {5, 5};
  Troop soldier(start_pos);

  text_man.load("pics/wallpaper.jpg", "background", 1920, 1080, win.get_renderer());
  text_man.load("pics/64x64.png", "troop", 64, 64, win.get_renderer());
  text_man.load("pics/black_64x64.png", "black", 64, 64, win.get_renderer());
  text_man.load("pics/building.png", "building", 64, 64, win.get_renderer());
  text_man.load("pics/grass.bmp", "grass", 64, 64, win.get_renderer());
  text_man.load("pics/circle.png", "circle", 64, 64, win.get_renderer());
  text_man.load("pics/circle2.png", "circle2", 64, 64, win.get_renderer());
  text_man.load("pics/panel.png", "panel", 260, 640, win.get_renderer());
  
  SDL_Rect* temp_rect_building = NULL;
  SDL_Rect* temp_rect_troop = NULL;
  bool building_selector = false;
  bool troop_selector = false;

  bool running = true;
  while (running) {
    /*user input handler. you can see the class*/
    input.input_handler(running, building_selector, troop_selector, temp_rect_building, temp_rect_troop);
    /*You have to use this method at this point, like render present at the end of the loop*/
    win.render_clear();
    
    text_man.draw_frame("background", 0, 0, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());       
    text_man.draw_frame_dyn("building", input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());        
    text_man.draw_frame_dyn_pro_tile("troop", soldier.get_cordinates().first, soldier.get_cordinates().second, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    temp_rect_troop = &text_man.get_actual_rect();

    ///text_man.draw_frame_dyn_pro_tile("troop", input.get_changing_x(), input.get_changing_y(), input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());

    { /*Static elements which are resistent of mouse mouvement to refresh the map*/
      text_man.draw_frame_static("panel", WINDOW_WIDTH, 0, win.get_renderer());
      text_man.draw_frame_static("building", WINDOW_WIDTH + 40, 60, win.get_renderer());
      /*here can I say that the last item is selectable. In the next step I have to make this data visible and load it into a vector*/
      temp_rect_building = &text_man.get_actual_rect();

      text_man.draw_frame_static("troop", WINDOW_WIDTH + 40, 144 + 190, win.get_renderer());

    }

    if (building_selector) {
      text_man.draw_frame_static("circle", WINDOW_WIDTH + 40, 60, win.get_renderer());
      Singleton::getInstance()->pin_mouse_click_to_map(input.get_mouse_x(), input.get_mouse_y());
    }

    if (troop_selector) {      
      text_man.draw_frame_dyn_pro_tile("circle2", soldier.get_cordinates().first, soldier.get_cordinates().second, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
      
      if (soldier.get_cordinates().first != input.get_mouse_x() || soldier.get_cordinates().second != input.get_mouse_y()) {        
        pf.find_path(soldier.get_cordinates().first, soldier.get_cordinates().second, input.get_mouse_x(), input.get_mouse_y());
        soldier.move_troop(); 
        SDL_Delay(50);
        
      }
    }


    /*As I mentioned here is the necessary render_present method to write on the screen the drawers results*/
    win.render_present();
  }
  /*And finally the closing method*/
  win.close();
  return 0;
}

/*game handler class is recommended and this could be a usefull method of it*/
int ticker(int steps) {
  int ticker_status = 0;
  ticker_status = int(((SDL_GetTicks() / 100) % steps));
  return ticker_status;
}

#endif

#ifndef CATCH_CONFIG_MAIN

int main(int argc, char* argv[]) {
  std::pair<int, int> start_pos = { 5, 5 };
  Troop soldier(start_pos);
  std::cout << soldier.get_cordinates().first << std::endl;
  std::cout << soldier.get_cordinates().second << std::endl;

  Path_finder pf;
  Singleton::getInstance()->initialize_tile_map();
  Singleton::getInstance()->fill_tile_map_with_plus_pattern();

  pf.find_path(0, 0, 10, 9);
  pf.scratch_route_to_temp_map();
  pf.print_temp_map();

  //Singleton::getInstance()->print_route();
  
  soldier.smooth_move_troop();
  soldier.smooth_move_troop();
  soldier.smooth_move_troop();
  Singleton::getInstance()->print_smooth_route();
  

  

  return 0;
}

#endif