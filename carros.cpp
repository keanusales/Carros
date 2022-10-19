#include "chassis.cpp"

// IMPLEMENTAÇÃO

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MAXCARS = 10;

ostream &operator<<(ostream &output, const Carros *carro) {
  output << carro->atributes.nameCar;
  return output;
}

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> atributes.nameCar = nameCar;
  this -> atributes.hpStock = hpStock;
  this -> atributes.hpAtual = hpStock;
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
  this -> myChassis = new Chassis();
  this -> numCars++;
}

Carros::Carros(const Carros *other) {
  *this = other;
  this -> numCars++;
}

Carros::~Carros() {
  delete myEngine, myTransmiss, myChassis;
  myEngine = 0, myTransmiss = 0, myChassis = 0;
  this -> numCars--;
}

void Carros::getAtributes() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Horsepower: " << atributes.hpAtual << "\n\n";
}

void Carros::getModsDone() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Partes do motor:\n" << myEngine << "\n";
  cout << "Partes da trasmissao:\n" << myTransmiss << "\n";
  cout << "Partes do Chassis:\n" << myChassis << "\n";
}

void Carros::setInternals(const int opcao) {
  this -> myEngine->setInternals(opcao);
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setTurbo(const int opcao) {
  system("cls||clear");
  if (this -> myEngine->setTurbo(opcao, atributes.hpAtual)) {
    const int hpAdd = Engine::turbosParts[opcao].hpGain;
    this -> atributes.hpAtual += hpAdd;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setIntake(const int opcao) {
  system("cls||clear");
  if (this -> myEngine->setIntake(opcao, atributes.hpAtual)) {
    const int hpAdd = Engine::intakeParts[opcao].hpGain;
    this -> atributes.hpAtual += hpAdd;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setExaust(const int opcao) {
  system("cls||clear");
  if (this -> myEngine->setExaust(opcao, atributes.hpAtual)) {
    const int hpAdd = Engine::exaustParts[opcao].hpGain;
    this -> atributes.hpAtual += hpAdd;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setECUnit(const int opcao) {
  system("cls||clear");
  if (this -> myEngine->setECUnit(opcao, atributes.hpAtual)) {
    const int hpAdd = Engine::ECUnitParts[opcao].hpGain;
    this -> atributes.hpAtual += hpAdd;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setTransmiss(const int opcao) {
  this -> myTransmiss->setTransmiss(opcao);
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setSuspension(const int opcao) {
  this -> myChassis->setSuspension(opcao);
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setChassis(const int opcao) {
  this -> myChassis->setChassis(opcao);
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

int Carros::getNumCars() { return numCars; }

int Carros::getMaxLen() { return MAXLEN; }

int Carros::getMinHP() { return MINHP; }

int Carros::getMaxHP() { return MAXHP; }

int Carros::getMaxCars() { return MAXCARS; }

// SOBRECARGAS

const Carros &Carros::operator=(const Carros *other) {
  this -> atributes = other->atributes;
  this -> myEngine = new Engine(other->myEngine);
  this -> myTransmiss = new Transmiss(other->myTransmiss);
  this -> myChassis = new Chassis(other->myChassis);
  return *this;
}

bool Carros::operator==(const string &name) const {
  return atributes.nameCar == name;
}

bool Carros::operator!=(const string &name) const {
  return !(*this == name);
}

bool Carros::operator!() const {
  return !(atributes.hpAtual > 1000);
}