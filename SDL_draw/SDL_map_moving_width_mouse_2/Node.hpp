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
  int priority;
  const int& estimate(const int& dest_x, const int& dest_y) const;
public:
  Node();
  Node(int _pos_x, int _pos_y, int _dest, int _prior);
  int get_pos_x();
  int get_pos_y();
  int get_level();
  int get_priority();
  void update_priority(const int& dest_x, const int& dest_y);
  void next_level(const int& i);
  ~Node();
};