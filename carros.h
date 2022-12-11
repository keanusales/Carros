#ifndef CARROS_H
#define CARROS_H

#include "vehicle.h"

struct argCarros {
  unsigned hpStock;
  double timeSwap;
  double gForce;
};

class Carros: public Vehicle {
  public:
    Carros(const string &, const argCarros &);
    Carros(const Carros &);
    ~Carros() {}
  
  public: // Virtual Functions
    Vehicle *clone();
    void output(ostream &) const;
    void setInterns();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransm();
    void setSuspens();
    void setChassis();

  private:
    Engine myEngine;
    Transm myTransm;
    Chassis myChassis;
};

#endif