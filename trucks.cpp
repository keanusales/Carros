#include "carros.cpp"

// IMPLEMENTAÇÃO

Trucks::Trucks(const string &nameTruck, const argTrucks &args):
  Vehicle(nameTruck), myEngine(args.hpStock),
  myTransm(args.timeSwap) {}

Trucks::Trucks(const Trucks &other):
  Vehicle(other), myEngine(other.myEngine),
  myTransm(other.myTransm) {}

Vehicle *Trucks::clone() { return new Trucks(*this); }

void Trucks::output(ostream &output) const {
  output << "Motor:\n" << this->myEngine << "\n";
  output << "Transmisao:\n" << this->myTransm << "\n";
}

void Trucks::tiraTeima() const {
  const unsigned hpAtual = myEngine.getHpower();
  const double timeSwap = myTransm.getTime();
  const double resul = 14 - log(hpAtual) + timeSwap;
  const double adver = resul + Vehicle::random();
  system("cls||clear");
  cout << "Seu tempo foi de " << resul << "s!\n";
  cout << "Seu adversaio fez " << adver << "s!\n";
  if (resul < adver) {
    cout << "Voce venceu seu adversario!\n\n";
    return;
  }
  if (resul > adver) {
    cout << "Voce perdeu pro adversario!\n\n";
    return;
  }
  cout << "Voce empatou com seu adversario!\n\n";
}

void Trucks::setInterns() {
  const bool resul = myEngine.setInterns();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setTurbos() {
  const bool resul = myEngine.setTurbos();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Trucks::setIntake() {
  const bool resul = myEngine.setIntake();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Trucks::setExaust() {
  const bool resul = myEngine.setExaust();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Trucks::setECUnit() {
  const bool resul = myEngine.setECUnit();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Trucks::setTransm() {
  const bool resul = myTransm.setTransm();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setSuspens() {
  cout << "Nao ha como modificar essa parte!\n";
}

void Trucks::setChassis() {
  cout << "Nao ha como modificar essa parte!\n";
}