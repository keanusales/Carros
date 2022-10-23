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

Transmiss::Transmiss(const Transmiss &other) { *this = other; }

Transmiss::~Transmiss() {}

void Transmiss::setTransmiss(const int opcao) {
  this -> myTransmiss = Transmiss::transmissParts[opcao];
}

const transmiss Transmiss::getTransmiss(const int opcao) {
  return Transmiss::transmissParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Transmiss &trasmiss) {
  output << "Transmission: " << trasmiss.myTransmiss.part << "\n";
  return output;
}

const Transmiss &Transmiss::operator=(const Transmiss &other) {
  this -> myTransmiss = other.myTransmiss;
  return *this;
}

const bool Transmiss::operator==(const string &part) const {
  return myTransmiss.part == part;
} //Esse

const bool Transmiss::operator!=(const string &part) const {
  return !(*this == part);
} //Esse

const bool Transmiss::operator!() const {
  return !(myTransmiss.time);
} //Esse

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const transmiss &elem) {
  output << elem.part << " - " << elem.time;
  return output;
}