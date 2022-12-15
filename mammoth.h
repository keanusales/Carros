#ifndef Mammoth_h
#define Mammoth_h

#include "fordf150.h"

class Mammoth: public Trucks {
  public:
    Mammoth();
    Mammoth(const Mammoth &);
    ~Mammoth() {}
  
  public: // Virtual Functions
    Vehicle *clone();

  private:
    static const argTrucks ARGS;
};

#endif