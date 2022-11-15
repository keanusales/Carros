#include "carros.cpp"

// IMPLEMENTAÇÃO

const int Trucks::MINHP = 350;
const int Trucks::MAXHP = 1400;

Trucks::Trucks(const string &nameTruck, const int hpStock)
: Vehicle(nameTruck, hpStock) {
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
}

Trucks::Trucks(const Trucks &other): Vehicle(other) {
  this -> myEngine = new Engine(*other.myEngine);
  this -> myTransmiss = new Transmiss(*other.myTransmiss);
}

Trucks::~Trucks() {
  delete myEngine, myTransmiss;
  myEngine = 0, myTransmiss = 0;
}

Vehicle *Trucks::clone() { return new Trucks(*this); }

void Trucks::setInternals(const int opcao) {
  const bool resul = myEngine->setInternals(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setTurbos(const int opcao) {
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
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setIntake(const int opcao) {
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
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setExaust(const int opcao) {
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
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setECUnit(const int opcao) {
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
  cout << "A parte selecionada ja esta no truck!\n";
}

void Trucks::setTransmiss(const int opcao) {
  const bool resul = myTransmiss->setTransmiss(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no truck!\n";
}

const int Trucks::getMinHP() { return MINHP; }

const int Trucks::getMaxHP() { return MAXHP; }

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Trucks &truck) {
  output << "Motor:\n" << *truck.myEngine << "\n";
  output << "Transmisao:\n" << *truck.myTransmiss << "\n";
  return output;
}