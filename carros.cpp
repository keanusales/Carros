#include "chassis.cpp"

// IMPLEMENTAÇÃO

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MAXCARS = 10;

Carros::Carros(const string &nameCar, const int hpStock) {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  const int dia = ltm->tm_mday;
  const int mes = 1 + ltm->tm_mon;
  const int ano = 1900 + ltm->tm_year;
  this -> atributes.nameCar = nameCar;
  this -> atributes.hpStock = hpStock;
  this -> atributes.hpAtual = hpStock;
  this -> atributes.diaCria = {dia, mes, ano};
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
  this -> myChassis = new Chassis();
  this -> numCars++;
}

Carros::Carros(const Carros &other) {
  *this = other; this -> numCars++;
}

Carros::~Carros() {
  delete myEngine, myTransmiss, myChassis;
  myEngine = 0, myTransmiss = 0, myChassis = 0;
  this -> numCars--;
}

void Carros::getAtributes() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Horsepower: " << atributes.hpAtual << "\n";
  cout << "Dia criacao: " << atributes.diaCria << "\n";
}

void Carros::getModsDone() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Partes do motor:\n" << *myEngine << "\n";
  cout << "Partes da trasmissao:\n" << *myTransmiss << "\n";
  cout << "Partes do Chassis:\n" << *myChassis << "\n";
}

void Carros::setInternals(const int opcao) {
  this -> myEngine->setInternals(opcao);
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setTurbo(const int opcao) {
  system("cls||clear");
  const int hpFinal = myEngine->setTurbo(opcao, atributes.hpStock);
  if (hpFinal) {
    this -> atributes.hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setIntake(const int opcao) {
  system("cls||clear");
  const int hpFinal = myEngine->setIntake(opcao, atributes.hpStock);
  if (hpFinal) {
    this -> atributes.hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setExaust(const int opcao) {
  system("cls||clear");
  const int hpFinal = myEngine->setExaust(opcao, atributes.hpStock);
  if (hpFinal) {
    this -> atributes.hpAtual = hpFinal;
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos nao aguentam ou sao originais!\n"
    << "Tente fazer um upgrade dos internos!\n";
}

void Carros::setECUnit(const int opcao) {
  system("cls||clear");
  const int hpFinal = myEngine->setECUnit(opcao, atributes.hpStock);
  if (hpFinal) {
    this -> atributes.hpAtual = hpFinal;
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

void Carros::checkDate(const int dia) const {
  system("cls||clear");
  const int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (dia > 0 && dia <= diasMes[atributes.diaCria.mes]) {
    cout << "O dia existe nesse mes e nesse ano!\n";
    return;
  }
  if (atributes.diaCria.mes == 2 && dia == 29 &&
    atributes.diaCria.ano % 400 == 0 ||
    (atributes.diaCria.ano % 4 == 0 &&
    atributes.diaCria.ano % 100 != 0)) {
    cout << "O dia existe nesse mes e nesse ano!\n";
    return;
  }
  cout << "O dia nao existe nesse mes e nesse ano!\n";
}

int Carros::getNumCars() { return numCars; }

int Carros::getMaxLen() { return MAXLEN; }

int Carros::getMinHP() { return MINHP; }

int Carros::getMaxHP() { return MAXHP; }

int Carros::getMaxCars() { return MAXCARS; }

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Carros &carro) {
  output << carro.atributes.nameCar;
  return output;
}

const Carros &Carros::operator=(const Carros &other) {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  const int dia = ltm->tm_mday;
  const int mes = 1 + ltm->tm_mon;
  const int ano = 1900 + ltm->tm_year;
  this -> atributes.nameCar = other.atributes.nameCar;
  this -> atributes.hpStock = other.atributes.hpStock;
  this -> atributes.hpAtual = other.atributes.hpAtual;
  this -> atributes.diaCria = {dia, mes, ano};
  this -> myEngine = new Engine(*other.myEngine);
  this -> myTransmiss = new Transmiss(*other.myTransmiss);
  this -> myChassis = new Chassis(*other.myChassis);
  return *this;
}

const bool Carros::operator==(const string &name) const {
  return atributes.nameCar == name;
} //Esse

const bool Carros::operator!=(const string &name) const {
  return !(*this == name);
} //Esse

const bool Carros::operator!() const {
  return !(atributes.hpAtual > 1000);
} //Esse

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const diaCria &elem) {
  output << elem.dia << "/" << elem.mes << "/" << elem.ano << "\n";
  return output;
}