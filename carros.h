#ifndef CARROS_H
#define CARROS_H

#include <iostream>
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    static void construct(Carros *[], const string &, const int);
    Carros(const string & = "Aleatorio", const int = 250);
    Carros(const Carros &);
    static void destuct(Carros *[], const int);
    ~Carros();
    void setStatus(const int);
    int verifyHP(const int) const;
    int verifyLevel(const int) const;
    static void statusArray(Carros *[]);
    static void namesArray(Carros *[]);
    static bool verifyEscolha(const int);
    static int getMaxCars();

  private:
    int hpAtual;
    int hpStock;
    int upLevel;
    string nameCar;
    static int numCars;
    static const int MINHP;
    static const int MAXHP;
    static const int MODHP;
    static const int MAXCARS;
};

#endif