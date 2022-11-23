#ifndef SUVS_H
#define SUVS_H

#include "sports.h"

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