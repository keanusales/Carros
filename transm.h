#ifndef TRASMISS_H
#define TRASMISS_H

#include "engine.h"

struct transm { string part; double time; };

class Transm {
  friend ostream &operator<<(ostream &, const Transm &);

  public:
    Transm();
    Transm(const Transm &);
    ~Transm() {}
    const bool setTransm();
    static const transm &getTransm();

  private: //Sobrecargas
    const bool operator==(const transm &) const;

  private: //Bibliotecas
    static const transm transmParts[];
  
  private:
    transm myTransm;
};

ostream &operator<<(ostream &, const transm &);

#endif