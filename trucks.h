#ifndef TRUCKS_H
#define TRUCKS_H

#include "carros.h"

struct argTrucks {
  unsigned hpStock;
  double timeSwap;
};

class Trucks: public Vehicle {
  public:
    Trucks(const string &, const argTrucks &);
    Trucks(const Trucks &);
    ~Trucks() {}
  
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
};

#endif