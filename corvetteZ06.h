#ifndef CorvetteZ06_h
#define CorvetteZ06_h

#include "trucks.h"

class CorvetteZ06: public Carros {
  public:
    CorvetteZ06();
    CorvetteZ06(const CorvetteZ06 &);
    ~CorvetteZ06() {}
  
  public: // Virtual Functions
    Vehicle *clone();

  private:
    static const argCarros ARGS;
};

#endif