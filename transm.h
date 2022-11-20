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

  private: //Sobrecargas
    const bool operator==(const transm &) const;

  private: //Bibliotecas
    static const transm transmParts[];
  
  private:
    static const transm &getTransm();
    transm myTransm;
};

ostream &operator<<(ostream &, const transm &);

#endif