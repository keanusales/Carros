#ifndef ENGINE_H
#define ENGINE_H

#include "include.h"

struct turbos { string part; unsigned hpGain; };
struct intake { string part; unsigned hpGain; };
struct exaust { string part; unsigned hpGain; };
struct ECUnit { string part; unsigned hpGain; };
struct intern { string part; unsigned hpResis; };

class Engine {
  friend ostream &operator<<(ostream &, const Engine &);

  public:
    Engine();
    Engine(const Engine &);
    ~Engine() {}
    const bool setInterns();
    const unsigned setTurbos(const unsigned);
    const unsigned setIntake(const unsigned);
    const unsigned setExaust(const unsigned);
    const unsigned setECUnit(const unsigned);

  private: //Sobrecargas
    const bool operator==(const turbos &) const;
    const bool operator==(const intake &) const;
    const bool operator==(const exaust &) const;
    const bool operator==(const ECUnit &) const;
    const bool operator==(const intern &) const;

  private: //Bibliotecas
    static const turbos turbosParts[];
    static const intake intakeParts[];
    static const exaust exaustParts[];
    static const ECUnit ECUnitParts[];
    static const intern internParts[];
  
  private:
    static const turbos &getTurbos();
    static const intake &getIntake();
    static const exaust &getExaust();
    static const ECUnit &getECUnit();
    static const intern &getIntern();
    turbos myTurbos;
    intake myIntake;
    exaust myExaust;
    ECUnit myECUnit;
    intern myIntern;
};

ostream &operator<<(ostream &, const intern &);
ostream &operator<<(ostream &, const turbos &);
ostream &operator<<(ostream &, const intake &);
ostream &operator<<(ostream &, const exaust &);
ostream &operator<<(ostream &, const ECUnit &);

#endif