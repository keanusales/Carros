#ifndef VEHICLE_H
#define VEHICLE_H

#include "chassis.h"

struct diaCria { unsigned dia, mes, ano; };
struct newVeh { string name; unsigned type; };

class Vehicle {
  friend ostream &operator<<(ostream &, const Vehicle &);
  friend ostream &operator<<(ostream &, const Vehicle *);

  public:
    Vehicle(const string &);
    Vehicle(const Vehicle &);
    virtual ~Vehicle() {}
    static Vehicle *create(const newVeh &);
    static const bool verString(const string &);
    static const bool verCreate(const unsigned);

  public: // Virtual Functions
    virtual Vehicle *clone() = 0;
    virtual void output(ostream &) const = 0;
    virtual void tiraTeima() const = 0;
    virtual void setInterns() = 0;
    virtual void setTurbos() = 0;
    virtual void setIntake() = 0;
    virtual void setExaust() = 0;
    virtual void setECUnit() = 0;
    virtual void setTransm() = 0;
    virtual void setSuspens() = 0;
    virtual void setChassis() = 0;

  protected:
    static const double random();

  private:
    string nameVeh;
    diaCria diaCria;
    static const unsigned MAXLEN;
    static unsigned prevRand;
};

ostream &operator<<(ostream &, const diaCria &);
const diaCria getDiaCria();

#endif