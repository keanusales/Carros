#ifndef Chassis_h
#define Chassis_h

#include "transm.h"

struct chassis { string part; double gForce; };
struct suspens { string part; double gForce; };

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis &);

  public:
    Chassis(const double &);
    Chassis(const Chassis &);
    ~Chassis() {}
    const bool setSuspens();
    const bool setChassis();
    static const double getGForce();

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
    double gForce;
    static const double MINGFORCE;
    static const double MAXGFORCE;
};

ostream &operator<<(ostream &, const chassis &);
ostream &operator<<(ostream &, const suspens &);

#endif