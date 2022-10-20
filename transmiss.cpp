#include "engine.cpp"

// DICIONÁRIOS

const Transmiss::trasmiss Transmiss::transmissParts[] = {
  {"Original Trasmission w/ Short Shifter, Sport Clutch", .2},
  {"Sport Trasmission w/ H-Pattern Short Shifter, Sport+ Clutch", .17},
  {"Sport Trasmission w/ Sequential Shifter, Racing Clutch", .14},
  {"Racing Sequential Trasmission w/ Pneumatic Shifter, Racing Clutch", .07}
};

// IMPLEMENTAÇÃO

Transmiss::Transmiss() {
  this -> myTransmiss = {"Original", 0};
}

Transmiss::Transmiss(const Transmiss *other) { *this = other; }

Transmiss::~Transmiss() {}

void Transmiss::setTransmiss(const int opcao) {
  this -> myTransmiss = Transmiss::transmissParts[opcao];
}

// SOBRECARGAS

ostream &operator<<(ostream &output, const Transmiss *trasmiss) {
  output << "Transmission: " << trasmiss->myTransmiss.part << "\n";
  return output;
}

const Transmiss &Transmiss::operator=(const Transmiss *other) {
  this -> myTransmiss = other->myTransmiss;
  return *this;
}

bool Transmiss::operator==(const string &part) const {
  return myTransmiss.part == part;
}

bool Transmiss::operator!=(const string &part) const {
  return !(*this == part);
}

bool Transmiss::operator!() const {
  return !(myTransmiss.time);
}