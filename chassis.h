#ifndef CHASSIS_H
#define CHASSIS_H

#include "transmiss.h"

struct chassis {
  string part;
  float gForce;
};
struct suspension {
  string part;
  float gForce;
};

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis &);

  public:
    Chassis();
    Chassis(const Chassis &);
    ~Chassis();
    void setSuspension(const int);
    void setChassis(const int);
    static const chassis getChassis(const int);
    static const suspension getSuspension(const int);

  public: //Sobrecargas
    const Chassis &operator=(const Chassis &);
    const bool operator==(const string &) const;
    const bool operator!=(const string &) const;
    const bool operator!() const;

  private: //Bibliotecas
    static const chassis chassisParts[];
    static const suspension suspensionParts[];
  
  private:
    chassis myChassis;
    suspension mySuspension;
};

ostream &operator<<(ostream &, const chassis &);
ostream &operator<<(ostream &, const suspension &);

#endif