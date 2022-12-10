#include "vehicle.cpp"

// IMPLEMENTAÇÃO

Carros::Carros(const string &nameCar, const unsigned hpStock)
: Vehicle(nameCar, hpStock) {
  this->myEngine = Engine();
  this->myTransm = Transm();
  this->myChassis = Chassis();
}

Carros::Carros(const Carros &other): Vehicle(other) {
  this->myEngine = Engine(other.myEngine);
  this->myTransm = Transm(other.myTransm);
  this->myChassis = Chassis(other.myChassis);
}

Vehicle *Carros::clone() { return new Carros(*this); }

void Carros::output(ostream &output) const {
  output << "Motor:\n" << this->myEngine << "\n";
  output << "Transmisao:\n" << this->myTransm << "\n";
  output << "Chassis:\n" << this->myChassis << "\n";
}

void Carros::setInterns() {
  const bool resul = myEngine.setInterns();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTurbos() {
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

void Carros::setIntake() {
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

void Carros::setExaust() {
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

void Carros::setECUnit() {
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

void Carros::setTransm() {
  const bool resul = myTransm.setTransm();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setSuspens() {
  const bool resul = myChassis.setSuspens();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setChassis() {
  const bool resul = myChassis.setChassis();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}