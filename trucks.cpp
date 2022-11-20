#include "carros.cpp"

// IMPLEMENTAÇÃO

Trucks::Trucks(const string &nameTruck, const unsigned hpStock)
: Vehicle(nameTruck, hpStock) {
  this -> myEngine = Engine();
  this -> myTransm = Transm();
}

Trucks::Trucks(const Trucks &other)
: Vehicle(static_cast <Vehicle> (other)) {
  this -> myEngine = Engine(other.myEngine);
  this -> myTransm = Transm(other.myTransm);
}

void Trucks::calling(const unsigned opcao) {
  typedef void (Trucks::*action)();
  const action actions[] = {
    &Trucks::printState, &Trucks::setInterns, &Trucks::setTurbos,
    &Trucks::setIntake, &Trucks::setExaust, &Trucks::setECUnit,
    &Trucks::setTransm, &Trucks::setSuspens, &Trucks::setChassis
  };
  ((*this).*actions[opcao])();
}

void Trucks::printState() {
  system("cls||clear"); cout << *this;
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
    this -> hpAtual = hpFinal;
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
    this -> hpAtual = hpFinal;
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
    this -> hpAtual = hpFinal;
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
    this -> hpAtual = hpFinal;
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

// SOBRACARGAS DA CLASSE

ostream &operator<<(ostream &output, const Trucks &truck) {
  output << static_cast <Vehicle> (truck) << "\n";
  output << "Motor:\n" << truck.myEngine << "\n";
  output << "Transmisao:\n" << truck.myTransm << "\n";
  return output;
}