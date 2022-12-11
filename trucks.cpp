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
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setIntake() {
  const bool resul = myEngine.setIntake();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setExaust() {
  const bool resul = myEngine.setExaust();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setECUnit() {
  const bool resul = myEngine.setECUnit();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
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