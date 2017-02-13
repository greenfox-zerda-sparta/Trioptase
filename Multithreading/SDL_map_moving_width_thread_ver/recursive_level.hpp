#pragma once
#include "Singleton.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>   

class recursive_level {
public:
  recursive_level();
  void drawer(int x, int y, int covered);
  void porgettyu(bool* running, bool* mazing);
};

