#include "carros.cpp"

// IMPLEMENTAÇÃO

Trucks::Trucks(const string &nameTruck, const unsigned hpStock)
: Vehicle(nameTruck, hpStock) {
  this->myEngine = Engine();
  this->myTransm = Transm();
}

Trucks::Trucks(const Trucks &other): Vehicle(other) {
  this->myEngine = Engine(other.myEngine);
  this->myTransm = Transm(other.myTransm);
}

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
  const unsigned hpFinal = myEngine.setTurbos(hpStock);
  system("cls||clear");
  if (hpFinal) {
    this->hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setIntake() {
  const unsigned hpFinal = myEngine.setIntake(hpStock);
  system("cls||clear");
  if (hpFinal) {
    this->hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setExaust() {
  const unsigned hpFinal = myEngine.setExaust(hpStock);
  system("cls||clear");
  if (hpFinal) {
    this->hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Trucks::setECUnit() {
  const unsigned hpFinal = myEngine.setECUnit(hpStock);
  system("cls||clear");
  if (hpFinal) {
    this->hpAtual = hpFinal;
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