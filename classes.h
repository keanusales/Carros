#ifndef CLASSES_H
#define CLASSES_H

#include "include.h"

// CLASSE ENGINE

class Engine {
  friend ostream &operator<<(ostream &, const Engine*);

  public:
    Engine();
    Engine(const Engine*);
    ~Engine();
    bool setTurbo(const int, const int);
    bool setIntake(const int, const int);
    bool setExaust(const int, const int);
    bool setECUnit(const int, const int);
    void setInternals(const int);

  public: //Bibliotecas
    static const struct turbo {
      string part;
      int hpGain;
    } turbosParts[];
    static const struct intake {
      string part;
      int hpGain;
    } intakeParts[];
    static const struct exaust {
      string part;
      int hpGain;
    } exaustParts[];
    static const struct ECUnit {
      string part;
      int hpGain;
    } ECUnitParts[];
    static const struct interns {
      string part;
      int hpResis;
    } internsParts[];
  
  private:
    turbo myTurbo;
    intake myIntake;
    exaust myExaust;
    ECUnit myECUnit;
    interns myInterns;
};

// CLASSE TRASMISS

class Transmiss {
  friend ostream &operator<<(ostream &, const Transmiss*);

  public:
    Transmiss();
    Transmiss(const Transmiss*);
    ~Transmiss();
    void setTransmiss(const int);

  public: //Bibliotecas
    static const struct trasmiss {
      string part;
      double time;
    } transmissParts[];
  
  private:
    trasmiss myTransmiss;
};

// CLASSE CHASSIS

class Chassis {
  friend ostream &operator<<(ostream &, const Chassis*);

  public:
    Chassis();
    Chassis(const Chassis*);
    ~Chassis();
    void setSuspension(const int);
    void setChassis(const int);

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