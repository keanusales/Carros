#ifndef VEHICLE_H
#define VEHICLE_H

#include "chassis.h"

struct diaCria {
  int dia, mes, ano;
};
struct newVeh {
  int typeVehicle;
  string nameVehicle;
  int hpStock;
};

class Vehicle {
  friend ostream &operator<<(ostream &, const Vehicle &);
  friend ostream &operator<<(ostream &, const Vehicle *);

  public:
    Vehicle(const string &, const int);
    Vehicle(const Vehicle &);
    virtual ~Vehicle();
    static Vehicle *create(const newVeh &);
    static const int getNumVehicle();
    static const int getMaxLen();
    static const int getMaxVehicle();

  public: // Virtual Functions
    virtual Vehicle *clone() = 0;
    virtual void setInternals(const int) {}
    virtual void setTurbos(const int) {}
    virtual void setIntake(const int) {}
    virtual void setExaust(const int) {}
    virtual void setECUnit(const int) {}
    virtual void setTransmiss(const int) {}
    virtual void setSuspens(const int) {}
    virtual void setChassis(const int) {}

  protected:
    int hpStock, hpAtual;

  private:
    string nameVehicle;
    diaCria diaCria;
    static int numVehicles;
    static const int MAXLEN;
    static const int MAXVEHICLES;
};

ostream &operator<<(ostream &, const diaCria &);
const diaCria getDiaCria();

#endif