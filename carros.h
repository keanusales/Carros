#ifndef CARROS_H
#define CARROS_H

#include "vehicle.h"

class Carros: public Vehicle {
  friend ostream &operator<<(ostream &, const Carros &);

  public:
    Carros(const string &, const unsigned);
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