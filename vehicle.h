#ifndef Vehicle_h
#define Vehicle_h

#include "chassis.h"

struct diaCria { unsigned dia, mes, ano; };

class Vehicle {
  friend ostream &operator<<(ostream &, const Vehicle &);
  friend ostream &operator<<(ostream &, const Vehicle *);

  public:
    Vehicle(const string &);
    Vehicle(const Vehicle &);
    virtual ~Vehicle() {}
    void setInterns();
    void setTurbos();
    void setIntake();
    void setExaust();
    void setECUnit();
    void setTransm();
    void setSuspens();
    void setChassis();
    static Vehicle *create(const unsigned &);
    static const string getNameVeh();
    static const bool verCreate(const unsigned);

  public: // Virtual Functions
    virtual Vehicle *clone() = 0;
    virtual void output(ostream &) const = 0;
    virtual void tiraTeima() const = 0;

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