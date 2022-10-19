#ifndef CARROS_H
#define CARROS_H

#include "chassis.h"

class Carros {
  friend ostream &operator<<(ostream &, const Carros*);

  public:
    Carros(const string &, const int);
    Carros(const Carros*);
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
    void setSuspension(const int);
    void setChassis(const int);
    static int getNumCars();
    static int getMaxLen();
    static int getMinHP();
    static int getMaxHP();
    static int getMaxCars();

  public: //Sobrecargas
    const Carros &operator=(const Carros*);
    bool operator==(const string &) const;
    bool operator!=(const string &) const;
    bool operator!() const;

  private:
    struct Atributes {
      int hpStock;
      int hpAtual;
      string nameCar;
    } atributes;
    Engine *myEngine;
    Transmiss *myTransmiss;
    Chassis *myChassis;
    static int numCars;
    static const int MAXLEN;
    static const int MINHP;
    static const int MAXHP;
    static const int MAXCARS;
};

int selectOption();
void createCar(Carros *[]);
void copyExtCar(Carros *[]);
void deleteCar(Carros *[]);
void getAtributes(Carros *[]);
void getModsDone(Carros *[]);
void setInternals(Carros *[]);
void setTurbo(Carros *[]);
void setIntake(Carros *[]);
void setExaust(Carros *[]);
void setEletronic(Carros *[]);
void setTransmission(Carros *[]);
void setSuspension(Carros *[]);
void setChassis(Carros *[]);
void exitProgram(Carros *[]);
int getEscolha(Carros *[]);
bool verifyEscolha(const int);
bool verifyName(const string &);
bool verifyHP(const int);

#endif