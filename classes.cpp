#include "dicts.cpp"

// CLASSE ENGINE

ostream &operator<<(ostream &output, const Engine *engine) {
  output << "Turbo: " << engine->myTurbo.part << "\n";
  output << "Intake: " << engine->myIntake.part << "\n";
  output << "Exaust: " << engine->myExaust.part << "\n";
  output << "ECUnit: " << engine->myECUnit.part << "\n";
  output << "Internals: " << engine->myInterns.part << "\n";
  return output;
}

Engine::Engine() {
  this -> myTurbo = {"Original", 0};
  this -> myIntake = {"Original", 0};
  this -> myExaust = {"Original", 0};
  this -> myECUnit = {"Original", 0};
  this -> myInterns = {"Original", 0};
}

Engine::Engine(const Engine *other) {
  this -> myTurbo = other->myTurbo;
  this -> myIntake = other->myIntake;
  this -> myExaust = other->myExaust;
  this -> myECUnit = other->myECUnit;
  this -> myInterns = other->myInterns;
}

Engine::~Engine() {}

void Engine::setInternals(const int opcao) {
  this -> myInterns = Engine::internsParts[opcao];
}

bool Engine::setTurbo(const int opcao, const int hpAtual) {
  if (myInterns.part == "Original") return 0;
  const int hpAdd = Engine::turbosParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myTurbo = Engine::turbosParts[opcao];
  return 1;
}

bool Engine::setIntake(const int opcao, const int hpAtual) {
  if (myIntake.part == "Original") return 0;
  const int hpAdd = Engine::intakeParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myIntake = Engine::intakeParts[opcao];
  return 1;
}

bool Engine::setExaust(const int opcao, const int hpAtual) {
  if (myInterns.part == "Original") return 0;
  const int hpAdd = Engine::exaustParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myExaust = Engine::exaustParts[opcao];
  return 1;
}

bool Engine::setECUnit(const int opcao, const int hpAtual) {
  if (myInterns.part == "Original") return 0;
  const int hpAdd = Engine::ECUnitParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myECUnit = Engine::ECUnitParts[opcao];
  return 1;
}

// CLASSE TRANSMISS

ostream &operator<<(ostream &output, const Transmiss *trasmiss) {
  output << "Transmission: " << trasmiss->myTransmiss.part << "\n";
  return output;
}

Transmiss::Transmiss() {
  this -> myTransmiss = {"Original", 0};
}

Transmiss::Transmiss(const Transmiss *other) {
  this -> myTransmiss = other->myTransmiss;
}

Transmiss::~Transmiss() {}

void Transmiss::setTransmiss(const int opcao) {
  this -> myTransmiss = Transmiss::transmissParts[opcao];
}

// CLASSE CHASSIS

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