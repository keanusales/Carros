#include "engine.cpp"

// DICIONÁRIOS

const transmiss Transmiss::transmissParts[] = {
  {"Original Trasmission w/ Short Shifter, Sport Clutch", .2},
  {"Sport Trasmission w/ H-Pattern Short Shifter, Sport+ Clutch", .17},
  {"Sport Trasmission w/ Sequential Shifter, Racing Clutch", .14},
  {"Racing Sequential Trasmission w/ Pneumatic Shifter, Racing Clutch", .07}
};

// IMPLEMENTAÇÃO

Transmiss::Transmiss() {
  this -> myTransmiss = {"Original", 0};
}

Transmiss::Transmiss(const Transmiss &other) {
  this -> myTransmiss = other.myTransmiss;
}

Transmiss::~Transmiss() {}

const bool Transmiss::setTransmiss(const int opcao) {
  const transmiss transmiss = Transmiss::transmissParts[opcao];
  if (*this == transmiss) return 0;
  this -> myTransmiss = transmiss;
  return 1;
}

const transmiss Transmiss::getTransmiss(const int opcao) {
  return Transmiss::transmissParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Transmiss &trasmiss) {
  output << "Transmission: " << trasmiss.myTransmiss << "\n";
  return output;
}

const bool Transmiss::operator==(const transmiss &part) const {
  return (myTransmiss.time == part.time && myTransmiss.part == part.part);
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const transmiss &elem) {
  output << elem.part << " - " << elem.time;
  return output;
}