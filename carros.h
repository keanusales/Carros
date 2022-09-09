#ifndef CARROS_H
#define CARROS_H

#include <iostream>
#include <string>
using namespace std;

class Carros {
  public:
    Carros();
    ~Carros();
    void upgrade(int);
    void printState(string) const;

  private:
    int horsepower, upgradeLevel;
};

#endif //CARROS_H