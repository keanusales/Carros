#ifndef CARROS_H
#define CARROS_H

#include "vehicle.h"

class Carros: public Vehicle {
  friend ostream &operator<<(ostream &, const Carros &);

  public:
    Carros(const string &, const int);
    Carros(const Carros &);
    ~Carros();
    Vehicle *clone();
    void setInternals(const int);
    void setTurbos(const int);
    void setIntake(const int);
    void setExaust(const int);
    void setECUnit(const int);
    void setTransmiss(const int);
    void setSuspens(const int);
    void setChassis(const int);
    static const int getMinHP();
    static const int getMaxHP();

  private:
    Engine *myEngine;
    Transmiss *myTransmiss;
    Chassis *myChassis;
    static const int MINHP;
    static const int MAXHP;
};

#endif