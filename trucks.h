#ifndef TRUCKS_H
#define TRUCKS_H

#include "carros.h"

class Trucks: public Vehicle {
  friend ostream &operator<<(ostream &, const Trucks &);

  public:
    Trucks(const string &, const unsigned);
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