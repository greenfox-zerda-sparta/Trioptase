#define CATCH_CONFIG_MAIN
#include "Window.hpp"
#include "Graphic.hpp"
#include "User_input.hpp"
#include "Map.hpp"
#include "Texture_manager.hpp"
#include "Node.hpp"
#include "Path_finder.hpp"


#ifndef CATCH_CONFIG_MAIN

const int WINDOW_WIDTH(640);
const int WINDOW_HEIGHT(640);
const int MAP_SIZE(30);

int ticker(int steps); //map size -4 is recommended but it must be adjusted

int main(int argc, char* argv[]) {

  Window win(WINDOW_WIDTH, WINDOW_HEIGHT);

  User_input input(WINDOW_WIDTH, WINDOW_HEIGHT);

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
    text_man.draw_frame("background", 0, 0, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on x automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", ticker_status, 3, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on y automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", 2, ticker_status, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda can walk on x and y automatically*/
    text_man.draw_frame_dyn_pro_tile("yoda", ticker_status, ticker_status, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*yoda holds its position on 4, 7*/
    text_man.draw_frame_dyn_pro_tile("yoda", 4, 7, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    
    /*you can controll yoda's movements on xy coords by direction buttons*/
    text_man.draw_frame_dyn_pro_tile("yoda", input.get_changing_x(), input.get_changing_y(), input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    /*here can I say that the last item is selectable. In the next step I have to make this data visible and load it into a vector*/
    temp_rect = &text_man.get_actual_rect();

    if (selector) {
      text_man.draw_frame_dyn_pro_tile("circle", input.get_changing_x(), input.get_changing_y(), input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
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

#endif

#ifdef CATCH_CONFIG_MAIN

const int n = 60; // horizontal size of the map
const int m = 60; // vertical size size of the map
std::vector<std::vector<int>> tile_map;
const int dir = 8;
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

using namespace std;
int main(int argc, char* argv[]) {
  srand(time(NULL));

  // create empty map
  tile_map.resize(n);
  for (int i = 0; i < tile_map.size(); i++) {
    tile_map[i].resize(m, 0);
  }

  // fillout the map matrix with a '+' pattern
  for (int x = n / 8; x<n * 7 / 8; x++) {
    tile_map[x][m / 2] = 1;
  }
  for (int y = m / 8; y<m * 7 / 8; y++) {
    tile_map[n / 2][y] = 1;
  }

  int xA, yA, xB, yB;
  xA = 1;
  yA = 1;
  xB = 59;
  yB = 59;

  cout << "Map Size (X,Y): " << n << "," << m << endl;
  cout << "Start: " << xA << "," << yA << endl;
  cout << "Finish: " << xB << "," << yB << endl;
  // get the route
  clock_t start = clock();

  Path_finder pf(tile_map);

  string route = pf.find_path(xA, yA, xB, yB);
  if (route == "") cout << "An empty route generated!" << endl;
  clock_t end = clock();
  double time_elapsed = double(end - start);
  cout << "Time to calculate the route (ms): " << time_elapsed << endl;
  cout << "Route:" << endl;
  cout << route << endl << endl;

  // follow the route on the map and display it 
  if (route.length()>0) {
    int j; char c;
    int x = xA;
    int y = yA;
    pf.map[x][y] = 2;
    for (int i = 0; i<route.length(); i++) {
      c = route.at(i);
      j = atoi(&c);
      x = x + dx[j];
      y = y + dy[j];
      pf.map[x][y] = 3;
    }
    pf.map[x][y] = 4;

    // display the map with the route
    for (int y = 0; y<m; y++) {
      for (int x = 0; x < n; x++) {
        if (pf.map[x][y] == 0)
          cout << ".";
        else if (pf.map[x][y] == 1)
          cout << "O"; //obstacle
        else if (pf.map[x][y] == 2)
          cout << "S"; //start
        else if (pf.map[x][y] == 3)
          cout << "R"; //route
        else if (pf.map[x][y] == 4)
          cout << "F"; //finish
        cout << endl;
      }
    }
  }
  getchar(); // wait for a (Enter) keypress  
  
  return 0;    
  }

#endif