#ifndef PorscheGT2_h
#define PorscheGT2_h

#include "corvetteZ06.h"

class PorscheGT2: public Carros {
  public:
    PorscheGT2();
    PorscheGT2(const PorscheGT2 &);
    ~PorscheGT2() {}
  
  public: // Virtual Functions
    Vehicle *clone();

  private:
    static const argCarros ARGS;
};

#endif