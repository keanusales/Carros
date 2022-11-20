#ifndef DERIVED_H
#define DERIVED_H

#include "trucks.h"

class Sports: public Carros {
  public:
    Sports(const string &, const unsigned);
    Sports(const Sports &);
    ~Sports() {}

  private:
    static const unsigned HPOWER;
};

class SUVs: public Carros {
  public:
    SUVs(const string &, const unsigned);
    SUVs(const SUVs &);
    ~SUVs() {}

  private:
    static const unsigned HPOWER;
};

#endif