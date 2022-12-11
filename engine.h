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
    Engine(const unsigned &);
    Engine(const Engine &);
    ~Engine() {}
    const bool setInterns();
    const bool setTurbos();
    const bool setIntake();
    const bool setExaust();
    const bool setECUnit();
    static const unsigned getHpStock();

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
    unsigned hpParts;
    unsigned hpAtual;
    static const unsigned MINHP;
    static const unsigned MAXHP;
};

ostream &operator<<(ostream &, const intern &);
ostream &operator<<(ostream &, const turbos &);
ostream &operator<<(ostream &, const intake &);
ostream &operator<<(ostream &, const exaust &);
ostream &operator<<(ostream &, const ECUnit &);

#endif