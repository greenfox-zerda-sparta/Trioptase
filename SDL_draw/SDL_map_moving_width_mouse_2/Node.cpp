#include "Node.hpp"

const int n = 60; // horizontal size of the map
const int m = 60; // vertical size size of the map
static int map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir = 8;
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

Node::Node() {
}

Node::Node(int _pos_x, int _pos_y, int _dest, int _prior) {
  this->pos_x = _pos_x;
  this->pos_y = _pos_y;
  this->level = _dest; // total distance already travelled to reach the node
  this->priority = _prior;
}

const int& Node::estimate(const int& dest_x, const int& dest_y) const {
  static int xd, yd, d;
  xd = dest_x - this->pos_x;
  yd = dest_y - this->pos_y;
  d = static_cast<int>(sqrt(xd * xd + yd * yd)); // Euclidian Distance
  return(d);
}

int Node::get_pos_x() {
  return this->pos_x;
}

int Node::get_pos_y() {
  return this->pos_x;
}

int Node::get_level() {
  return this->level;
}

int Node::get_priority() {
  return this->priority;
}

void Node::update_priority(const int& dest_x, const int& dest_y) {
  priority = level + estimate(dest_x, dest_y) * 10;
}

void Node::next_level(const int& i) {
  this->level += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
}

Node::~Node() {
}
