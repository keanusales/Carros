#ifndef CARROS_H
#define CARROS_H

#include <iostream>
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    Carros(string, int = 250);
    Carros(const Carros &);
    void setStatus(int);
    void getStatus() const;
    string getName() const;
    int verifyHP(int) const;
    int verifyLevel(int) const;

  private:
    int hpAtual;
    int hpStock;
    int upLevel;
    string nameCar;
    bool isUpgraded;
    static int quantCarros;
    static const int MINHP;
    static const int MAXHP;
    static const int MODHP;
};

#endif