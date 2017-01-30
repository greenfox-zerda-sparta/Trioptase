#include "Path_finder.hpp"

const int n = 60; // horizontal size of the map
const int m = 60; // vertical size size of the map
static int map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir = 8;
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

Path_finder::Path_finder() {
}

std::string Path_finder::find_path(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y) {
  static std::priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
  static int pqi; // pq index
  static Node* n0;
  static Node* m0;
  static int i, j, x, y, xdx, ydy;
  static char c;
  pqi = 0;

  // reset the node maps
  for (y = 0; y < m; y++) {
    for (x = 0; x < n; x++) {
      closed_nodes_map[x][y] = 0;
      open_nodes_map[x][y] = 0;
    }
  }

  // create the start node and push into list of open nodes
  n0 = new Node(start_x, start_y, 0, 0);
  n0->update_priority(finish_x, finish_y);
  pq[pqi].push(*n0);
  open_nodes_map[x][y] = n0->get_priority(); // mark it on the open nodes map
                           
  while (!pq[pqi].empty()) { // A* search get the current node w/ the highest priority from the list of open nodes
    n0 = new Node(pq[pqi].top().get_pos_x(), pq[pqi].top().get_pos_y(), pq[pqi].top().get_level(), pq[pqi].top().get_priority());

    x = n0->get_pos_x();
    y = n0->get_pos_y();

    pq[pqi].pop(); // remove the node from the open list
    open_nodes_map[x][y] = 0;
    
    closed_nodes_map[x][y] = 1; // mark it on the closed nodes map
    
    if (x == finish_x && y == finish_y) { // quit searching when the goal state is reached   
      std::string path = "";// generate the path from finish to start by following the directions
      while (!(x == start_x && y == start_y)) {
        j = dir_map[x][y];
        c = '0' + (j + dir / 2) % dir;
        path = c + path;
        x += dx[j];
        y += dy[j];
      }
     
      delete n0;

      while (!pq[pqi].empty()) pq[pqi].pop(); // empty the leftover nodes
      return path;
    }
    
    for (i = 0; i<dir; i++) { // generate moves (child nodes) in all possible directions
      xdx = x + dx[i]; ydy = y + dy[i];

      if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || map[xdx][ydy] == 1 || closed_nodes_map[xdx][ydy] == 1)) {
        // generate a child node
        m0 = new Node(xdx, ydy, n0->get_level(), n0->get_priority());
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
                         
          if (pq[pqi].size()>pq[1 - pqi].size()) pqi = 1 - pqi; // empty the larger size pq to the smaller one
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
  return ""; // no route found
}

Path_finder::~Path_finder() {
}
