#ifndef TRASMISS_H
#define TRASMISS_H

#include "engine.h"

struct transm { string part; double timeSwap; };

class Transm {
  friend ostream &operator<<(ostream &, const Transm &);

  public:
    Transm(const double &);
    Transm(const Transm &);
    ~Transm() {}
    const double getTime() const;
    const bool setTransm();
    static const double getTimeSwap();

  private: //Sobrecargas
    const bool operator==(const transm &) const;

  private: //Bibliotecas
    static const transm transmParts[];
  
  private:
    static const transm &getTransm();
    transm myTransm;
    double timeSwap;
    static const double MINTIME;
    static const double MAXTIME;
};

ostream &operator<<(ostream &, const transm &);

#endif