#ifndef CHASSIS_H
#define CHASSIS_H

#include "transmiss.h"

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis*);

  public:
    Chassis();
    Chassis(const Chassis*);
    ~Chassis();
    void setSuspension(const int);
    void setChassis(const int);

  public: //Sobrecargas
    const Chassis &operator=(const Chassis*);
    bool operator==(const string &) const;
    bool operator!=(const string &) const;
    bool operator!() const;

  public: //Bibliotecas
    static const struct chassis {
      string part;
      float gForce;
    } chassisParts[];
    static const struct suspension {
      string part;
      float gForce;
    } suspensionParts[];
  
  private:
    chassis myChassis;
    suspension mySuspension;
};

#endif