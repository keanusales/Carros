#ifndef ENGINE_H
#define ENGINE_H

#include "include.h"

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

  public: //Sobrecargas
    const Engine &operator=(const Engine*);
    bool operator==(const string &) const;
    bool operator!=(const string &) const;
    bool operator!() const;

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

#endif