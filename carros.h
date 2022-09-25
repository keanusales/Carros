#ifndef CARROS_H
#define CARROS_H

#include <iostream>
using std::getline;
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    Carros(const string &, const int);
    Carros(const Carros &);
    ~Carros();
    static void setNewCar(Carros *[]);
    static void copyExtCar(Carros *[]);
    static void deleteCar(Carros *[]);
    static void chooseCar(Carros *[]);
    static int getEscolha(Carros *[]);
    static bool verifyEscolha(const int);
    static bool verifyName(const string &);
    static bool verifyHP(const int);
    static void getStatusArray(Carros *[]);
    void verifyLevel(const int);
    void setStatus(const int);
    static int getMaxCars();

  private:
    int hpAtual;
    int hpStock;
    int upLevel;
    string nameCar;
    static int numCars;
    static const int MAXLEN;
    static const int MINHP;
    static const int MAXHP;
    static const int MODHP;
    static const int MAXCARS;
};

#endif