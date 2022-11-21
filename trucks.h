#ifndef TRUCKS_H
#define TRUCKS_H

#include "carros.h"

class Trucks: public Vehicle {
  friend ostream &operator<<(ostream &, const Trucks &);

  public:
    Trucks(const string &, const unsigned);
    Trucks(const Trucks &);
    ~Trucks() {}

  public: //Virtual Function
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
};

#endif