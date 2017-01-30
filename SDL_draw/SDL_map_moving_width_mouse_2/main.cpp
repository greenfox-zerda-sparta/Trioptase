#include "Window.hpp"
#include "Graphic.hpp"
#include "User_input.hpp"
#include "Map.hpp"
#include "Texture_manager.hpp"

const int WINDOW_WIDTH(640);
const int WINDOW_HEIGHT(640);
const int MAP_SIZE(30);

int ticker(int steps); //map size -4 is recommended but it must be adjusted

int main(int argc, char* argv[]) {

  Window win(WINDOW_WIDTH, WINDOW_HEIGHT);

  User_input input;

  Texture_manager text_man(WINDOW_WIDTH, WINDOW_HEIGHT);

  text_man.load("pics/wallpaper.jpg", "background", 1920, 1080, win.get_renderer());
  text_man.load("pics/64x64.png", "yoda", 64, 64, win.get_renderer());
  text_man.load("pics/black_64x64.png", "black", 64, 64, win.get_renderer());
  text_man.load("pics/building.bmp", "builing", 128, 128, win.get_renderer());
  text_man.load("pics/grass.bmp", "grass", 64, 64, win.get_renderer());
  text_man.load("pics/circle.png", "circle", 64, 64, win.get_renderer());
  
  SDL_Rect* temp_rect = NULL;
  bool selector = false;

  bool running = true;
  while (running) {
    /*user input handler. you can see the class*/
    input.input_handler(running, selector, temp_rect);
    /*You have to use this method at this point, like render present at the end of the loop*/
    win.render_clear();

    int ticker_status;
    /*ticker to automatically movements*/
    ticker_status = ticker(MAP_SIZE - 4);
    /*Inside of the methodes there are coded some usefull function, e.g mouse controlled "camera frame view"*/
    /*for the static background*/
    text_man.draw_frame("background", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on x automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", ticker_status, 3, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on y automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", 2, ticker_status, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on x and y automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", ticker_status, ticker_status, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda holds its position on 4, 7*/
    text_man.draw_frame_dyn_pro_tile("yoda", 4, 7, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    
    /*you can controll yoda's movements on xy coords by direction buttons*/
    text_man.draw_frame_dyn_pro_tile("yoda", input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*here can I say that the last item is selectable. In the next step I have to make this data visible and load it into a vector*/
    temp_rect = &text_man.get_actual_rect();

    if (selector) {
      text_man.draw_frame_dyn_pro_tile("circle", input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    }

    if (input.get_changing_y() > 64 + (float)128 * 0.2) {
    /*here you can define the order of objects but this is not sophistical solution. It's existed just for demonstration purpose*/
    }
    else {
      
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