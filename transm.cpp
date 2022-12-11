#include "engine.cpp"

// DICIONÁRIOS

const transm Transm::transmParts[] = {
  {"Original Trasmission w/ Short Shifter, Sport Clutch", .2},
  {"Sport Trasmission w/ H-Pattern Short Shifter, Sport+ Clutch", .17},
  {"Sport Trasmission w/ Sequential Shifter, Racing Clutch", .14},
  {"Racing Pneumatic Sequential Trasmission, Racing Clutch", .07}
};

// IMPLEMENTAÇÃO

const double Transm::MINTIME = .1;
const double Transm::MAXTIME = .27;

Transm::Transm(const double &timeSwap) {
  this->myTransm = {"Original", timeSwap};
  this->timeSwap = timeSwap;
}

Transm::Transm(const Transm &other) {
  this->myTransm = other.myTransm;
  this->timeSwap = other.timeSwap;
}

const double Transm::getTime() const {
  return this->timeSwap;
}

const bool Transm::setTransm() {
  const transm transm = getTransm();
  if (*this == transm) return 0;
  this->timeSwap = transm.timeSwap;
  this->myTransm = transm;
  return 1;
}

const double Transm::getTimeSwap() {
  while (1) {
    string input; double timeSwap;
    cout << "Digite o tempo de troca de marchas: ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> timeSwap && MINTIME <= timeSwap
      && timeSwap <= MAXTIME) return timeSwap;
    system("cls||clear");
    cout << "O tempo deve ficar entre .1 e .27s!\n";
  }
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
  output << "Tempo de Troca: " << trasmiss.timeSwap << "\n";
  output << "Transmission: " << trasmiss.myTransm << "\n";
  return output;
}

const bool Transm::operator==(const transm &part) const {
  return (myTransm.timeSwap == part.timeSwap && myTransm.part == part.part);
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const transm &elem) {
  output << elem.part << " - " << elem.timeSwap;
  return output;
}