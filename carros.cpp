#include "dicts.cpp"

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MINLVL = 0;
const int Carros::MAXLVL = 6;
const int Carros::MAXCARS = 10;

ostream &operator<<(ostream &output, const Carros *carro) {
  output << carro->atributes.nameCar;
  return output;
}

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> atributes.nameCar = nameCar;
  this -> atributes.hpStock = hpStock;
  this -> atributes.hpAtual = hpStock;
  this -> atributes.upLevel = 0;
  this -> modsDone.turbo.part = "Original";
  this -> modsDone.intake.part = "Original";
  this -> modsDone.exaust.part = "Original";
  this -> modsDone.eletronic.part = "Original";
  this -> modsDone.internals.part = "Original";
  this -> modsDone.suspension.part = "Original";
  this -> modsDone.trasmission.part = "Original";
  this -> modsDone.chassis.part = "Original";
  this -> numCars++;
}

Carros::Carros(const Carros &other) {
  this -> atributes = other.atributes;
  this -> modsDone = other.modsDone;
  this -> numCars++;
}

Carros::~Carros() { this -> numCars--; }

void Carros::getAtributes() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Horsepower: " << atributes.hpAtual << "\n";
  cout << "UpLevel: " << atributes.upLevel << "\n\n";
}

void Carros::getModsDone() const {
  cout << "Carro: " << atributes.nameCar << "\n";
  cout << "Turbo: " << modsDone.turbo.part << "\n";
  cout << "Intake: " << modsDone.intake.part << "\n";
  cout << "Exaust: " << modsDone.exaust.part << "\n";
  cout << "Eletronic: " << modsDone.eletronic.part << "\n";
  cout << "Internals: " << modsDone.internals.part << "\n";
  cout << "Trasmission: " << modsDone.trasmission.part << "\n";
  cout << "Suspension: " << modsDone.suspension.part << "\n";
  cout << "Chassis: " << modsDone.chassis.part << "\n\n";
}

void Carros::setInternals(const int opcao) {
  this -> modsDone.internals = Carros::internals[opcao];
}

void Carros::setTurbo(const int opcao) {
  this -> modsDone.turbo = Carros::turbos[opcao];
}

void Carros::setIntake(const int opcao) {
  this -> modsDone.intake = Carros::intake[opcao];
}

void Carros::setExaust(const int opcao) {
  this -> modsDone.exaust = Carros::exaust[opcao];
}

void Carros::setEletronic(const int opcao) {
  this -> modsDone.eletronic = Carros::eletronics[opcao];
}

void Carros::setTransmission(const int opcao) {
  this -> modsDone.trasmission = Carros::trasmission[opcao];
}

void Carros::setSuspension(const int opcao) {
  this -> modsDone.suspension = Carros::suspension[opcao];
}

void Carros::setChassis(const int opcao) {
  this -> modsDone.chassis = Carros::chassis[opcao];
}

int Carros::getNumCars() { return numCars; }

int Carros::getMaxLen() { return MAXLEN; }

int Carros::getMinHP() { return MINHP; }

int Carros::getMaxHP() { return MAXHP; }

int Carros::getMaxCars() { return MAXCARS; }