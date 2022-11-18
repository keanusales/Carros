#ifndef ENGINE_H
#define ENGINE_H

#include "include.h"

struct turbo {
  string part;
  int hpGain;
};
struct intake {
  string part;
  int hpGain;
};
struct exaust {
  string part;
  int hpGain;
};
struct ECUnit {
  string part;
  int hpGain;
};
struct intern {
  string part;
  int hpResis;
};

class Engine {
  friend ostream &operator<<(ostream &, const Engine &);

  public:
    Engine();
    Engine(const Engine &);
    ~Engine();
    const bool setInternals();
    const int setTurbo(const int);
    const int setIntake(const int);
    const int setExaust(const int);
    const int setECUnit(const int);
    static const turbo getTurbo();
    static const intake getIntake();
    static const exaust getExaust();
    static const ECUnit getECUnit();
    static const intern getIntern();

  public: //Sobrecargas
    const bool operator==(const turbo &) const;
    const bool operator==(const intake &) const;
    const bool operator==(const exaust &) const;
    const bool operator==(const ECUnit &) const;
    const bool operator==(const intern &) const;

  private: //Bibliotecas
    static const turbo turbosParts[];
    static const intake intakeParts[];
    static const exaust exaustParts[];
    static const ECUnit ECUnitParts[];
    static const intern internParts[];
  
  private:
    turbo myTurbo;
    intake myIntake;
    exaust myExaust;
    ECUnit myECUnit;
    intern myIntern;
};

ostream &operator<<(ostream &, const intern &);
ostream &operator<<(ostream &, const turbo &);
ostream &operator<<(ostream &, const intake &);
ostream &operator<<(ostream &, const exaust &);
ostream &operator<<(ostream &, const ECUnit &);

#endif