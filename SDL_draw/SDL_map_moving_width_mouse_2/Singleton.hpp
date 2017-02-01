#pragma once
#include <iostream>
#include <string>

using namespace std;

class Singleton {
private:        
  static Singleton* mInstance;        
  int mId;        
  Singleton(int _Id) {
    mId = _Id;
  }
public:        
  static void initialize(int _Id) {
    mInstance = new Singleton(_Id);
  }
  static Singleton* getInstance() {
    return mInstance;
  }
  void setId(int _Id) {
    mId = _Id;
  }
  void print() {
    cout << this << " |  " << mId << endl;
  }
};

Singleton* Singleton::mInstance = NULL;