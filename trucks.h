#ifndef Trucks_h
#define Trucks_h

#include "carros.h"

struct argTrucks {
  string nameVeh;
  unsigned hpStock;
  double timeSwap;
};

class Trucks: public Vehicle {
  friend ostream &operator<<(ostream &, const Trucks &);

  public:
    Trucks(const argTrucks &);
    Trucks(const Trucks &);
    ~Trucks() {}
    void setInterns();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransm();
  
  public: // Virtual Functions
    void output(ostream &) const;
    void tiraTeima() const;

  private:
    Engine myEngine;
    Transm myTransm;
};

#endif