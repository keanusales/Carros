#include "transmiss.cpp"

// DICIONÁRIOS

const suspens Chassis::suspensParts[] = {
  {"Semi-Slick Tires w/ Sport Suspension (shock absorbers, springs)", 0.8},
  {"Semi-Slick Tires w/ Racing Suspension (shock absorbers, springs, bushings etc)", 1},
  {"Slick Tires w/ Full Racing Suspension (coilovers, bushings, stabilizer bars etc)", 1.2}
};

const chassis Chassis::chassisParts[] = {
  {"Chassis reinforcement w/ Simple Rollcage (screwed)", 0.6},
  {"Chassis reinforcement w/ Simple Rollcage (welded), better aerodynamics", 1.1},
  {"Reinforcement w/ Racing Rollcage (welded), better aerodynamics, locked suspension", 1.6}
};

// IMPLEMENTAÇÃO

Chassis::Chassis() {
  this -> mySuspens = {"Original", 0};
  this -> myChassis = {"Original", 0};
}

Chassis::Chassis(const Chassis &other) {
  this -> mySuspens = other.mySuspens;
  this -> myChassis = other.myChassis;
}

Chassis::~Chassis() {}

const bool Chassis::setSuspens(const int opcao) {
  const suspens suspens = Chassis::suspensParts[opcao];
  if (*this == suspens) return 0;
  *this = suspens;
  return 1;
}

const bool Chassis::setChassis(const int opcao) {
  const chassis chassis = Chassis::chassisParts[opcao];
  if (*this == chassis) return 0;
  *this = chassis;
  return 1;
}

const chassis Chassis::getChassis(const int opcao) {
  return Chassis::chassisParts[opcao];
}

const suspens Chassis::getSuspens(const int opcao) {
  return Chassis::suspensParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Chassis &chassis) {
  output << "Suspension: " << chassis.myChassis.part << "\n";
  output << "Chassis: " << chassis.myChassis.part << "\n";
  return output;
}

const Chassis &Chassis::operator=(const chassis &part) {
  this -> myChassis = part;
  return *this;
}

const Chassis &Chassis::operator=(const suspens &part) {
  this -> mySuspens = part;
  return *this;
}

const bool Chassis::operator==(const chassis &part) const {
  if (myChassis.gForce == part.gForce) return 1;
  if (myChassis.part == part.part) return 1;
  return 0;
}

const bool Chassis::operator==(const suspens &part) const {
  if (mySuspens.gForce == part.gForce) return 1;
  if (mySuspens.part == part.part) return 1;
  return 0;
}

const bool Chassis::operator!=(const chassis &part) const {
  return !(*this == part);
}

const bool Chassis::operator!=(const suspens &part) const {
  return !(*this == part);
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const chassis &elem) {
  output << elem.part << " - " << elem.gForce;
  return output;
}

ostream &operator<<(ostream &output, const suspens &elem) {
  output << elem.part << " - " << elem.gForce;
  return output;
}