#include "Singleton.hpp"

Singleton* Singleton::mInstance = NULL;

Singleton::Singleton() {
}

Singleton* Singleton::getInstance() {
  if (mInstance == NULL) {
    mInstance = new Singleton;
  }
  return mInstance;
}

void Singleton::print() {
  std::cout << this << std::endl;
}