#ifndef CARROS_H
#define CARROS_H

#include "vehicle.h"

class Carros: public Vehicle {
  public:
    Carros(const string &, const int);
    Carros(const Carros &);
    ~Carros();
    Vehicle *clone();
    void setInternals();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransmiss();
    void setSuspens();
    void setChassis();
    static const int getMinHP();
    static const int getMaxHP();

  public: // Virtual Get for Ostream
    void getout(ostream &) const;

  private:
    Engine *myEngine;
    Transmiss *myTransmiss;
    Chassis *myChassis;
    static const int MINHP;
    static const int MAXHP;
};

#endif