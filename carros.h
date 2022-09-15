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
    const int MINHP;
    const int MAXHP;
    const int MODHP;
};

#endif