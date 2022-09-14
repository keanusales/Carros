#ifndef CARROS_H
#define CARROS_H

#include <iostream>
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    Carros(int = 250);
    Carros(const Carros &);
    void setStatus(int);
    void getStatus(string) const;
    int verifyHP(int) const;
    int verifyLevel(int) const;

  private:
    int hpAtual;
    int hpStock;
    int upLevel;
    const int MINHP = 250;
    const int MAXHP = 700;
    const int MODHP = 1500;
};

#endif