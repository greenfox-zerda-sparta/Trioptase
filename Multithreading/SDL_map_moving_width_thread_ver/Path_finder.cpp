#include "Path_finder.hpp"

const int MAP_SIZE(30);
const int n = 30; // horizontal size of the map
const int m = 30; // vertical size size of the map
///std::vector<std::vector<int>> tile_map;
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m];   // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir = 8; // number of possible directions to go at any position                   
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

Path_finder::Path_finder() {
}

void Path_finder::find_path(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y) {
  static priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
  static int pqi; // pq index
  static Node* n0;
  static Node* m0;
  static int i, j, x, y, xdx, ydy;  
  int ind = 0;
  int temp_finish_x = finish_x;
  int temp_finish_y = finish_y;
  pqi = 0;

  Singleton::getInstance()->reset_route();

  for (y = 0; y < m; y++) { // reset the node maps
    for (x = 0; x < n; x++) {
      closed_nodes_map[x][y] = 0;
      open_nodes_map[x][y] = 0;
    }
  }

  n0 = new Node(start_x, start_y, 0, 0);     // create the start node and push into list of open nodes
  n0->update_priority(finish_x, finish_y);
  pq[pqi].push(*n0);
  open_nodes_map[x][y] = n0->get_priority(); // mark it on the open nodes map

/* A* search */
  while (!pq[pqi].empty()) { // get the current node w/ the highest priority from the list of open nodes
    n0 = new Node(pq[pqi].top().get_pos_x(), pq[pqi].top().get_pos_y(), pq[pqi].top().get_level(), pq[pqi].top().get_priority());
    x = n0->get_pos_x(); y = n0->get_pos_y();
    pq[pqi].pop(); // remove the node from the open list
    open_nodes_map[x][y] = 0;
    closed_nodes_map[x][y] = 1; // mark it on the closed nodes map

    if (x == finish_x && y == finish_y) { // quit searching when the goal state is reached
      while (!(x == start_x && y == start_y)) {
        j = dir_map[x][y];        
        ind = (j + dir / 2) % dir;

        /*pushback dir vector of coord pairs*/
        temp_finish_x -= dx[ind];
        temp_finish_y -= dy[ind];
        Singleton::getInstance()->route.push_back(std::make_pair(temp_finish_x, temp_finish_y));       
       
        x += dx[j];
        y += dy[j];
      }
      delete n0;
      while (!pq[pqi].empty()) {
        pq[pqi].pop();
      }
      Singleton::getInstance()->route.pop_back();
      return;
    }

    for (i = 0; i < dir; i++) { // generate moves (child nodes) in all possible directions
      xdx = x + dx[i]; ydy = y + dy[i];

      if (!(xdx < 0 || xdx > n - 1 || ydy < 0 || ydy > m - 1 || Singleton::getInstance()->tile_map[xdx][ydy] == 1 || closed_nodes_map[xdx][ydy] == 1)) {
        m0 = new Node(xdx, ydy, n0->get_level(), n0->get_priority());   // generate a child node        
        m0->next_level(i);
        m0->update_priority(finish_x, finish_y);

        if (open_nodes_map[xdx][ydy] == 0) { // if it is not in the open list then add into that
          open_nodes_map[xdx][ydy] = m0->get_priority();
          pq[pqi].push(*m0);
          dir_map[xdx][ydy] = (i + dir / 2) % dir; // mark its parent node direction
        }
        else if (open_nodes_map[xdx][ydy]>m0->get_priority()) {
          open_nodes_map[xdx][ydy] = m0->get_priority(); // update the priority info          
          dir_map[xdx][ydy] = (i + dir / 2) % dir; // update the parent direction info

          while (!(pq[pqi].top().get_pos_x() == xdx && pq[pqi].top().get_pos_y() == ydy)) { // replace the node by emptying one pq to the other one except the node to be replaced will be ignored and the new node will be pushed in instead
            pq[1 - pqi].push(pq[pqi].top());
            pq[pqi].pop();
          }

          pq[pqi].pop(); // remove the wanted node

          if (pq[pqi].size() > pq[1 - pqi].size()) { // empty the larger size pq to the smaller one
            pqi = 1 - pqi;
          }
          while (!pq[pqi].empty()) {
            pq[1 - pqi].push(pq[pqi].top());
            pq[pqi].pop();
          }

          pqi = 1 - pqi;
          pq[pqi].push(*m0); // add the better node instead
        }
        else delete m0; // garbage collection
      }
    }
    delete n0; // garbage collection
  }
  return; // no route found
}

void Path_finder::scratch_route_to_temp_map() {
  this->temp_tile_map = Singleton::getInstance()->tile_map;
  for (int i = 0; i < Singleton::getInstance()->route.size(); i++) {   
    this->temp_tile_map[Singleton::getInstance()->route[i].first][Singleton::getInstance()->route[i].second] = 4;
  }
}

void Path_finder::print_temp_map() {
  if (!this->temp_tile_map.empty()) {
    for (int y = 0; y < this->temp_tile_map.size(); y++) {
      for (int x = 0; x < this->temp_tile_map[y].size(); x++) {
        std::cout << this->temp_tile_map[x][y];
      }
      std::cout << std::endl;
    }
  }
  this->temp_tile_map.clear();
}

Path_finder::~Path_finder(){
}
