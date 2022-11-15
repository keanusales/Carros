#ifndef TRASMISS_H
#define TRASMISS_H

#include "engine.h"

struct transmiss {
  string part;
  double time;
};

class Transmiss {
  friend ostream &operator<<(ostream &, const Transmiss &);

  public:
    Transmiss();
    Transmiss(const Transmiss &);
    ~Transmiss();
    const bool setTransmiss(const int);
    static const transmiss getTransmiss(const int);

  public: //Sobrecargas
    const bool operator==(const transmiss &) const;

  private: //Bibliotecas
    static const transmiss transmissParts[];
  
  private:
    transmiss myTransmiss;
};

ostream &operator<<(ostream &, const transmiss &);

#endif