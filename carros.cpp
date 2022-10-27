#include "chassis.cpp"

// IMPLEMENTAÇÃO

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MAXCARS = 10;

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> atributes.nameCar = nameCar;
  this -> atributes.hpStock = hpStock;
  this -> atributes.hpAtual = hpStock;
  this -> diaCria = getData();
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
  this -> myChassis = new Chassis();
  this -> numCars++;
}

Carros::Carros(const Atributes &entrie) {
  this -> atributes = entrie;
  this -> diaCria = getData();
  this -> myEngine = new Engine();
  this -> myTransmiss = new Transmiss();
  this -> myChassis = new Chassis();
  this -> numCars++;
}

Carros::Carros(const Carros &other) {
  this -> atributes = other.atributes;
  this -> diaCria = getData();
  this -> myEngine = new Engine(*other.myEngine);
  this -> myTransmiss = new Transmiss(*other.myTransmiss);
  this -> myChassis = new Chassis(*other.myChassis);
  this -> numCars++;
}

Carros::~Carros() {
  delete myEngine, myTransmiss, myChassis;
  myEngine = 0, myTransmiss = 0, myChassis = 0;
  this -> numCars--;
}

void Carros::getAtributes() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Horsepower: " << atributes.hpAtual << "\n";
  cout << "Dia da criacao: " << diaCria << "\n";
}

void Carros::getModsDone() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Partes do motor:\n" << *myEngine << "\n";
  cout << "Partes da trasmissao:\n" << *myTransmiss << "\n";
  cout << "Partes do Chassis:\n" << *myChassis << "\n";
}

void Carros::setInternals(const int opcao) {
  const bool resul = myEngine->setInternals(opcao);
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTurbo(const int opcao) {
  const int hpFinal = myEngine->setTurbo(opcao, atributes.hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> atributes.hpAtual = hpFinal;
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
  const int hpFinal = myEngine->setIntake(opcao, atributes.hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> atributes.hpAtual = hpFinal;
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
  const int hpFinal = myEngine->setExaust(opcao, atributes.hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> atributes.hpAtual = hpFinal;
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
  const int hpFinal = myEngine->setECUnit(opcao, atributes.hpStock);
  system("cls||clear");
  if (hpFinal > 0) {
    this -> atributes.hpAtual = hpFinal;
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

void Carros::checkDate(const int dia) const {
  system("cls||clear");
  const int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (dia > 0 && dia <= diasMes[diaCria.mes]) {
    cout << "O dia existe nesse mes e nesse ano!\n";
    return;
  }
  if (diaCria.mes == 2 && dia == 29 && diaCria.ano % 400 == 0
    || (diaCria.ano % 4 == 0 && diaCria.ano % 100 != 0)) {
    cout << "O dia existe nesse mes e nesse ano!\n";
    return;
  }
  cout << "O dia nao existe nesse mes e nesse ano!\n";
}

const diaCria Carros::getData() const {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  const int dia = ltm->tm_mday;
  const int mes = 1 + ltm->tm_mon;
  const int ano = 1900 + ltm->tm_year;
  return {dia, mes, ano};
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

const bool Carros::operator!=(const turbo &part) const {
  return *myEngine != part;
}

const bool Carros::operator!=(const intake &part) const {
  return *myEngine != part;
}

const bool Carros::operator!=(const exaust &part) const {
  return *myEngine != part;
}

const bool Carros::operator!=(const ECUnit &part) const {
  return *myEngine != part;
}

const bool Carros::operator!=(const intern &part) const {
  return *myEngine != part;
}

const bool Carros::operator!=(const transmiss &part) const {
  return *myTransmiss != part;
}

const bool Carros::operator!=(const suspens &part) const {
  return *myChassis != part;
}

const bool Carros::operator!=(const chassis &part) const {
  return *myChassis != part;
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const diaCria &elem) {
  output << elem.dia << "/" << elem.mes << "/" << elem.ano << "\n";
  return output;
}