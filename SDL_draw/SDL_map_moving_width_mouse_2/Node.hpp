#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>

class Node {
private:
  int pos_x;
  int pos_y;
  int level;
  int priority;  // smaller: higher priority
  const int& estimate(const int& xDest, const int& yDest) const;
public:
  Node(int xp, int yp, int d, int p);
  int get_pos_x() const;
  int get_pos_y() const;
  int get_level() const;
  int get_priority() const;
  void update_priority(const int& xDest, const int& yDest);
  void next_level(const int& i);
  ~Node();
};

bool operator<(const Node& a, const Node& b);
