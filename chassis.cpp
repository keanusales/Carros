#include "transmiss.cpp"

// DICIONÁRIOS

const Chassis::suspension Chassis::suspensionParts[] = {
  {"Semi-Slick Tires w/ Sport Suspension (shock absorbers, springs)", 0.8},
  {"Semi-Slick Tires w/ Racing Suspension (shock absorbers, springs, bushings etc)", 1},
  {"Slick Tires w/ Full Racing Suspension (coilovers, bushings, stabilizer bars etc)", 1.2}
};

const Chassis::chassis Chassis::chassisParts[] = {
  {"Chassis reinforcement w/ Simple Rollcage (screwed)", 0.6},
  {"Chassis reinforcement w/ Simple Rollcage (welded), better aerodynamics", 1.1},
  {"Reinforcement w/ Racing Rollcage (welded), better aerodynamics, locked suspension", 1.6}
};

// IMPLEMENTAÇÃO

ostream &operator<<(ostream &output, const Chassis *chassis) {
  output << "Suspension: " << chassis->myChassis.part << "\n";
  output << "Chassis: " << chassis->myChassis.part << "\n";
  return output;
}

Chassis::Chassis() {
  this -> mySuspension = {"Original", 0};
  this -> myChassis = {"Original", 0};
}

Chassis::Chassis(const Chassis *other) {
  this -> mySuspension = other->mySuspension;
  this -> myChassis = other->myChassis;
}

Chassis::~Chassis() {}

void Chassis::setSuspension(const int opcao) {
  this -> mySuspension = Chassis::suspensionParts[opcao];
}

void Chassis::setChassis(const int opcao) {
  this -> myChassis = Chassis::chassisParts[opcao];
}