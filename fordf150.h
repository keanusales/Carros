#ifndef FordF150_h
#define FordF150_h

#include "porscheGT2.h"

class FordF150: public Trucks {
  public:
    FordF150();
    FordF150(const FordF150 &);
    ~FordF150() {}
  
  public: // Virtual Functions
    Vehicle *clone();

  private:
    static const argTrucks ARGS;
};

#endif