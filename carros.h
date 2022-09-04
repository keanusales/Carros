#ifndef CARROS_H
#define CARROS_H

#include <iostream>
#include <string>
using namespace std;

class Carros {
  public:
    Carros();
    ~Carros();
    void upgrade(int level);
    void printState(string nome) const;

  private:
    int horsepower;
    int upgradeLevel;
};

#endif //CARROS_H