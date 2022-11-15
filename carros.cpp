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

void Carros::setInternals(const int opcao) {
  const bool resul = myEngine->setInternals(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTurbos(const int opcao) {
  const int hpFinal = myEngine->setTurbo(opcao, hpStock);
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

void Carros::setIntake(const int opcao) {
  const int hpFinal = myEngine->setIntake(opcao, hpStock);
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

void Carros::setExaust(const int opcao) {
  const int hpFinal = myEngine->setExaust(opcao, hpStock);
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

void Carros::setECUnit(const int opcao) {
  const int hpFinal = myEngine->setECUnit(opcao, hpStock);
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

void Carros::setTransmiss(const int opcao) {
  const bool resul = myTransmiss->setTransmiss(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setSuspens(const int opcao) {
  const bool resul = myChassis->setSuspens(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setChassis(const int opcao) {
  const bool resul = myChassis->setChassis(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

const int Carros::getMinHP() { return MINHP; }

const int Carros::getMaxHP() { return MAXHP; }

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Carros &carro) {
  output << "Motor:\n" << *carro.myEngine << "\n";
  output << "Transmisao:\n" << *carro.myTransmiss << "\n";
  output << "Chassis:\n" << *carro.myChassis << "\n";
  return output;
}