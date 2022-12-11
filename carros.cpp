#include "vehicle.cpp"

// IMPLEMENTAÇÃO

Carros::Carros(const string &nameCar, const argCarros &args):
  Vehicle(nameCar), myEngine(args.hpStock),
  myTransm(args.timeSwap), myChassis(args.gForce) {}

Carros::Carros(const Carros &other):
  Vehicle(other), myEngine(other.myEngine),
  myTransm(other.myTransm), myChassis(other.myChassis) {}

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
  const bool resul = myEngine.setTurbos();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setIntake() {
  const bool resul = myEngine.setIntake();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setExaust() {
  const bool resul = myEngine.setExaust();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setECUnit() {
  const bool resul = myEngine.setECUnit();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
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