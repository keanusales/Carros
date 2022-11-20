#ifndef CHASSIS_H
#define CHASSIS_H

#include "transm.h"

struct chassis { string part; float gForce; };
struct suspens { string part; float gForce; };

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis &);

  public:
    Chassis();
    Chassis(const Chassis &);
    ~Chassis() {}
    const bool setSuspens();
    const bool setChassis();

  private: //Sobrecargas
    const bool operator==(const chassis &) const;
    const bool operator==(const suspens &) const;

  private: //Bibliotecas
    static const chassis chassisParts[];
    static const suspens suspensParts[];
  
  private:
    static const chassis &getChassis();
    static const suspens &getSuspens();
    chassis myChassis;
    suspens mySuspens;
};

ostream &operator<<(ostream &, const chassis &);
ostream &operator<<(ostream &, const suspens &);

#endif