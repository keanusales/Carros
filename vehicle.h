#ifndef VEHICLE_H
#define VEHICLE_H

#include "chassis.h"

struct diaCria { unsigned dia, mes, ano; };

class Vehicle {
  friend ostream &operator<<(ostream &, const Vehicle &);

  public:
    Vehicle(const string &, const unsigned);
    Vehicle(const Vehicle &);
    virtual ~Vehicle() {}
    string getName() const;

  public: //Virtual Function
    virtual void calling(const unsigned) {}

  protected:
    unsigned hpStock, hpAtual;

  private:
    string nameVehicle;
    diaCria diaCria;
};

ostream &operator<<(ostream &, const diaCria &);
const diaCria getDiaCria();

#endif