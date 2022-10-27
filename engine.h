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
    const int setTurbo(const int, const int);
    const int setIntake(const int, const int);
    const int setExaust(const int, const int);
    const int setECUnit(const int, const int);
    const bool setInternals(const int);
    static const turbo getTurbo(const int);
    static const intake getIntake(const int);
    static const exaust getExaust(const int);
    static const ECUnit getECUnit(const int);
    static const intern getIntern(const int);

  public: //Sobrecargas
    const Engine &operator=(const turbo &);
    const Engine &operator=(const intake &);
    const Engine &operator=(const exaust &);
    const Engine &operator=(const ECUnit &);
    const Engine &operator=(const intern &);
    const bool operator==(const turbo &) const;
    const bool operator==(const intake &) const;
    const bool operator==(const exaust &) const;
    const bool operator==(const ECUnit &) const;
    const bool operator==(const intern &) const;
    const bool operator!=(const turbo &) const;
    const bool operator!=(const intake &) const;
    const bool operator!=(const exaust &) const;
    const bool operator!=(const ECUnit &) const;
    const bool operator!=(const intern &) const;
    const bool operator!() const;

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