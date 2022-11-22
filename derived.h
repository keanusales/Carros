#ifndef DERIVED_H
#define DERIVED_H

#include "trucks.h"

class Sports: public Carros {
  friend ostream &operator<<(ostream &, const Sports &);

  public:
    Sports(const string &, const unsigned);
    Sports(const Vehicle &);
    Sports(const Sports &);
    ~Sports() {}

  public: //Virtual Function
    void calling(const unsigned);

  private:
    void printState();
    static const unsigned HPOWER;
};

class SUVs: public Carros {
  friend ostream &operator<<(ostream &, const SUVs &);

  public:
    SUVs(const string &, const unsigned);
    SUVs(const Vehicle &);
    SUVs(const SUVs &);
    ~SUVs() {}

  public: //Virtual Function
    void calling(const unsigned);

  private:
    void printState();
    static const unsigned HPOWER;
};

#endif