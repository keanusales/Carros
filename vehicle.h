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

  public: //Pointers to functions
    typedef void (Vehicle::*action)();
    const action actions[9] = {
      &Vehicle::printState,
      &Vehicle::setInterns,
      &Vehicle::setTurbos,
      &Vehicle::setIntake,
      &Vehicle::setExaust,
      &Vehicle::setECUnit,
      &Vehicle::setTransm,
      &Vehicle::setSuspens,
      &Vehicle::setChassis
    };

  public: //Virtual Functions
    virtual void printState() {}
    virtual void setInterns() {}
    virtual void setTurbos() {}
    virtual void setIntake() {}
    virtual void setExaust() {}
    virtual void setECUnit() {}
    virtual void setTransm() {}
    virtual void setSuspens() {}
    virtual void setChassis() {}

  protected:
    unsigned hpStock, hpAtual;

  private:
    string nameVehicle;
    diaCria diaCria;
};

ostream &operator<<(ostream &, const diaCria &);
const diaCria getDiaCria();

#endif