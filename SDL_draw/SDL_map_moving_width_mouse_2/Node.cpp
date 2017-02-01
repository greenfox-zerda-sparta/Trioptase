#include "Node.hpp"
const int dir = 8;

const int& Node::estimate(const int& xDest, const int& yDest) const {
  static int xd, yd, d;
  xd = xDest - pos_x;
  yd = yDest - pos_y;
  d = static_cast<int>(sqrt(xd * xd + yd * yd)); // Euclidian Distance
  return(d);
}

Node::Node(int xp, int yp, int d, int p) {
  this->pos_x = xp;
  this->pos_y = yp;
  this->level = d;
  this->priority = p;
}

int Node::get_pos_x() const {
  return this->pos_x;
}

int Node::get_pos_y() const {
  return this->pos_y;
}

int Node::get_level() const {
  return this->level;
}

int Node::get_priority() const {
  return this->priority;
}

void Node::update_priority(const int& xDest, const int& yDest) {
  this->priority = this->level + estimate(xDest, yDest) * 10; //A*
}

void Node::next_level(const int& i) {
  this->level += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
}

Node::~Node() {
}

bool operator<(const Node& a, const Node& b) { // Determine priority (in the priority queue)
  return a.get_priority() > b.get_priority();
}