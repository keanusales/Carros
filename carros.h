#ifndef CARROS_H
#define CARROS_H

#include <map>
using std::map;

#include <iostream>
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    Carros(const string, int = 250);
    Carros(const Carros &);
    void setStatus(int);
    void getStatus() const;
    string getName() const;
    int verifyHP(int) const;
    int verifyLevel(int) const;
    static void getNumCars();
    static void getDanger();

  private:
    int hpAtual;
    int hpStock;
    int upLevel;
    bool isDanger;
    string nameCar;
    static int numCars;
    static int numUpDone;
    static const int MINHP;
    static const int MAXHP;
    static const int MODHP;
};

#endif