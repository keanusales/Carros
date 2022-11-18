#ifndef CHASSIS_H
#define CHASSIS_H

#include "transmiss.h"

struct chassis {
  string part;
  float gForce;
};
struct suspens {
  string part;
  float gForce;
};

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis &);

  public:
    Chassis();
    Chassis(const Chassis &);
    ~Chassis();
    const bool setSuspens();
    const bool setChassis();
    static const chassis getChassis();
    static const suspens getSuspens();

  public: //Sobrecargas
    const bool operator==(const chassis &) const;
    const bool operator==(const suspens &) const;

  private: //Bibliotecas
    static const chassis chassisParts[];
    static const suspens suspensParts[];
  
  private:
    chassis myChassis;
    suspens mySuspens;
};

ostream &operator<<(ostream &, const chassis &);
ostream &operator<<(ostream &, const suspens &);

#endif