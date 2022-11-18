#ifndef TRUCKS_H
#define TRUCKS_H

#include "carros.h"

class Trucks: public Vehicle {
  public:
    Trucks(const string &, const int);
    Trucks(const Trucks &);
    ~Trucks();
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
    static const int MINHP;
    static const int MAXHP;
};

#endif