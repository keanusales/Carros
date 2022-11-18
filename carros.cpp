#include "vehicle.cpp"

// IMPLEMENTAÇÃO

const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;

Carros::Carros(const string &nameCar, const int hpStock)
: Vehicle(nameCar, hpStock) {
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
  this -> myChassis = new Chassis();
}

Carros::Carros(const Carros &other): Vehicle(other) {
  this -> myEngine = new Engine(*other.myEngine);
  this -> myTransmiss = new Transmiss(*other.myTransmiss);
  this -> myChassis = new Chassis(*other.myChassis);
}

Carros::~Carros() {
  delete myEngine, myTransmiss, myChassis;
  myEngine = 0, myTransmiss = 0, myChassis = 0;
}

Vehicle *Carros::clone() { return new Carros(*this); }

void Carros::setInternals() {
  const bool resul = myEngine->setInternals();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTurbos() {
  const int hpFinal = myEngine->setTurbo(hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  if (!hpFinal) {
    cout << "Internos nao aguentam ou sao originais!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setIntake() {
  const int hpFinal = myEngine->setIntake(hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  if (!hpFinal) {
    cout << "Internos nao aguentam ou sao originais!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setExaust() {
  const int hpFinal = myEngine->setExaust(hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  if (!hpFinal) {
    cout << "Internos nao aguentam ou sao originais!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setECUnit() {
  const int hpFinal = myEngine->setECUnit(hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  if (!hpFinal) {
    cout << "Internos nao aguentam ou sao originais!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTransmiss() {
  const bool resul = myTransmiss->setTransmiss();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setSuspens() {
  const bool resul = myChassis->setSuspens();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setChassis() {
  const bool resul = myChassis->setChassis();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

const int Carros::getMinHP() { return MINHP; }

const int Carros::getMaxHP() { return MAXHP; }

// Virtual Get for Ostream

void Carros::getout(ostream &output) const {
  output << "Motor:\n" << *myEngine << "\n";
  output << "Transmisao:\n" << *myTransmiss << "\n";
  output << "Chassis:\n" << *myChassis << "\n";
}