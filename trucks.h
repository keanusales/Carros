#ifndef TRUCKS_H
#define TRUCKS_H

#include "carros.h"

class Trucks: public Vehicle {
  friend ostream &operator<<(ostream &, const Trucks &);

  public:
    Trucks(const string &, const int);
    Trucks(const Trucks &);
    ~Trucks();
    Vehicle *clone();
    void setInternals(const int);
    void setTurbos(const int);
    void setIntake(const int);
    void setExaust(const int);
    void setECUnit(const int);
    void setTransmiss(const int);
    static const int getMinHP();
    static const int getMaxHP();

  private:
    Engine *myEngine;
    Transmiss *myTransmiss;
    static const int MINHP;
    static const int MAXHP;
};

#endif