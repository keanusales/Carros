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

const bool Transmiss::setTransmiss() {
  const transmiss transmiss = getTransmiss();
  if (*this == transmiss) return 0;
  this -> myTransmiss = transmiss;
  return 1;
}

const transmiss Transmiss::getTransmiss() {
  int opcao;
  system("cls||clear");
  while (1) {
    string input; int cont = 0;
    for (transmiss elem : transmissParts)
      cout << cont++ << " - " << elem << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao)
      if (0 <= opcao && opcao < cont) break;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
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