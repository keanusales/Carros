#ifndef CARROS_H
#define CARROS_H

#include "chassis.h"

struct diaCria {
  int dia, mes, ano;
};
struct Atributes {
  int hpStock;
  int hpAtual;
  string nameCar;
};

class Carros {
  friend ostream &operator<<(ostream &, const Carros &);

  public:
    Carros(const string &, const int);
    Carros(const Atributes &);
    Carros(const Carros &);
    ~Carros();
    void verifyLevel(const int);
    void getAtributes() const;
    void getModsDone() const;
    void setTurbo(const int);
    void setIntake(const int);
    void setExaust(const int);
    void setECUnit(const int);
    void setInternals(const int);
    void setTransmiss(const int);
    void setSuspens(const int);
    void setChassis(const int);
    void checkDate(const int) const;
    static int getNumCars();
    static int getMaxLen();
    static int getMinHP();
    static int getMaxHP();
    static int getMaxCars();

  public: //Sobrecargas
    // const Carros &operator=(const Carros &);
    // const bool operator==(const string &) const;
    const bool operator!=(const turbo &) const;
    const bool operator!=(const intake &) const;
    const bool operator!=(const exaust &) const;
    const bool operator!=(const ECUnit &) const;
    const bool operator!=(const intern &) const;
    const bool operator!=(const transmiss &) const;
    const bool operator!=(const suspens &) const;
    const bool operator!=(const chassis &) const;
    // const bool operator!() const;

  private:
    const diaCria getData() const;
    Atributes atributes;
    diaCria diaCria;
    Engine *myEngine;
    Transmiss *myTransmiss;
    Chassis *myChassis;
    static int numCars;
    static const int MAXLEN;
    static const int MINHP;
    static const int MAXHP;
    static const int MAXCARS;
};

ostream &operator<<(ostream &, const diaCria &);

// FUNÇÕES DA MAIN

const int selectOption();
void createCar(Carros *[]);
void copyExtCar(Carros *[]);
void deleteCar(Carros *[]);
void getAtributes(Carros *[]);
void getModsDone(Carros *[]);
void setTurbo(Carros *[]);
void setIntake(Carros *[]);
void setExaust(Carros *[]);
void setECUnit(Carros *[]);
void setInternals(Carros *[]);
void setTransmiss(Carros *[]);
void setSuspens(Carros *[]);
void setChassis(Carros *[]);
void checkDate(Carros *[]);
void exitProgram(Carros *[]);
const int getEscolha(Carros *[]);
const bool verifyEscolha(const int);
const bool verifyName(const string &);
const bool verifyHP(const int);

#endif