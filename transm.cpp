#include "engine.cpp"

// DICIONÁRIOS

const transm Transm::transmParts[] = {
  {"Original Trasmission w/ Short Shifter, Sport Clutch", .2},
  {"Sport Trasmission w/ H-Pattern Short Shifter, Sport+ Clutch", .17},
  {"Sport Trasmission w/ Sequential Shifter, Racing Clutch", .14},
  {"Racing Sequential Trasmission w/ Pneumatic Shifter, Racing Clutch", .07}
};

// IMPLEMENTAÇÃO

Transm::Transm() {
  this->myTransm = {"Original", 0};
}

Transm::Transm(const Transm &other) {
  this->myTransm = other.myTransm;
}

const bool Transm::setTransm() {
  const transm transm = getTransm();
  if (*this == transm) return 0;
  this->myTransm = transm;
  return 1;
}

const transm &Transm::getTransm() {
  unsigned opcao;
  system("cls||clear");
  while (1) {
    string input; unsigned cont = 0;
    for (transm elem : transmParts)
      cout << cont++ << " - " << elem << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao && opcao < cont) break;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return Transm::transmParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Transm &trasmiss) {
  output << "Transmission: " << trasmiss.myTransm << "\n";
  return output;
}

const bool Transm::operator==(const transm &part) const {
  return (myTransm.time == part.time && myTransm.part == part.part);
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const transm &elem) {
  output << elem.part << " - " << elem.time;
  return output;
}