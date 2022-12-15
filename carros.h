#ifndef Carros_h
#define Carros_h

#include "vehicle.h"

struct argCarros {
  string nameVeh;
  unsigned hpStock;
  double timeSwap;
  double gForce;
};

class Carros: public Vehicle {
  friend ostream &operator<<(ostream &, const Carros &);

  public:
    Carros(const argCarros &);
    Carros(const Carros &);
    ~Carros() {}
    void setInterns();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransm();
    void setSuspens();
    void setChassis();
  
  public: // Virtual Functions
    Vehicle *clone();
    void output(ostream &) const;
    void tiraTeima() const;

  private:
    Engine myEngine;
    Transm myTransm;
    Chassis myChassis;
};

#endif