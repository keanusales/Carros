#ifndef TRASMISS_H
#define TRASMISS_H

#include "engine.h"

class Transmiss {
  friend ostream &operator<<(ostream &, const Transmiss*);

  public:
    Transmiss();
    Transmiss(const Transmiss*);
    ~Transmiss();
    void setTransmiss(const int);

  public: //Sobrecargas
    const Transmiss &operator=(const Transmiss*);
    bool operator==(const string &) const;
    bool operator!=(const string &) const;
    bool operator!() const;

  public: //Bibliotecas
    static const struct trasmiss {
      string part;
      double time;
    } transmissParts[];
  
  private:
    trasmiss myTransmiss;
};

#endif