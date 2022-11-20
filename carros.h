#ifndef CARROS_H
#define CARROS_H

#include "vehicle.h"

class Carros: public Vehicle {
  friend ostream &operator<<(ostream &, const Carros &);

  public:
    Carros(const string &, const unsigned);
    Carros(const Carros &);
    ~Carros() {}
    void calling(const unsigned);

  private:
    void printState();
    void setInterns();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransm();
    void setSuspens();
    void setChassis();
    Engine myEngine;
    Transm myTransm;
    Chassis myChassis;
};

#endif