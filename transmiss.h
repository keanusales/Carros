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
    void setTransmiss(const int);
    static const transmiss getTransmiss(const int);

  public: //Sobrecargas
    const Transmiss &operator=(const Transmiss &);
    const bool operator==(const string &) const;
    const bool operator!=(const string &) const;
    const bool operator!() const;

  private: //Bibliotecas
    static const transmiss transmissParts[];
  
  private:
    transmiss myTransmiss;
};

ostream &operator<<(ostream &, const transmiss &);

#endif