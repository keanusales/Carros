#include "carros.h"

// DICIONÁRIOS

const turbo Engine::turbosParts[] = {
  {"MasterPr 550-AH", 280}, {"Precision 650-LS", 360},
  {"Garrett 750-XT", 450}, {"2x MasterPr 550-AH", 500},
  {"2x Precision 650-LS", 670}, {"2x Garrett 750-XT", 840}
};

const intake Engine::intakeParts[] = {
  {"2 inch intake, Sport Filter, Original Head", 30},
  {"2.5 inch intake, Sport Filter, Original Head w/ Sport Camshaft", 90},
  {"3 inch intake, Racing Filter, CNC Head w/ Sport Camshaft", 165},
  {"3.5 intake w/ flow work, Racing Filter, CNC Head w/ Racing Camshaft", 260}
};

const exaust Engine::exaustParts[] = {
  {"3 inch stainless steel exaust w/ Sport Silencers", 70},
  {"3 inch titanium exaust w/ Racing Silencers", 90},
  {"3.5 inch titanium exaust w/ no Silencers", 110}
};

const ECUnit Engine::ECUnitParts[] = {
  {"Fueltech FT550 w/ Original Harness", 70},
  {"Fueltech FT600 w/ Racing Harness", 100}
};

const intern Engine::internParts[] = {
  {"Piston RP-650, Rod XXt-700", 640},
  {"Piston RP-800, Rod XXt-790", 780},
  {"Piston RP-1000, Rod XXt-970", 970},
  {"Piston RP-1300, Rod XXt-1320, Forged Crankshaft", 1290},
  {"Piston RP-1650, Rod XXt-1640, Billet Crankshaft", 1630},
  {"Piston RP-2000+, Rod XXt-2000+, Billet Crankshaft, Billet Block", 2500}
};

// IMPLEMENTAÇÃO

Engine::Engine() {
  this -> myTurbo = {"Original", 0};
  this -> myIntake = {"Original", 0};
  this -> myExaust = {"Original", 0};
  this -> myECUnit = {"Original", 0};
  this -> myIntern = {"Original", 0};
}

Engine::Engine(const Engine &other) { *this = other; }

Engine::~Engine() {}

void Engine::setInternals(const int opcao) {
  this -> myIntern = Engine::internParts[opcao];
}

const int Engine::setTurbo(const int opcao, const int hpStock) {
  if (*this == "Original") return 0;
  const int turbo = Engine::turbosParts[opcao].hpGain;
  const int hpFinal = hpStock + turbo + myIntake.hpGain
    + myExaust.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  this -> myTurbo = Engine::turbosParts[opcao];
  return hpFinal;
}

const int Engine::setIntake(const int opcao, const int hpStock) {
  if (*this == "Original") return 0;
  const int intake = Engine::intakeParts[opcao].hpGain;
  const int hpFinal = hpStock + intake + myTurbo.hpGain
    + myExaust.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  this -> myIntake = Engine::intakeParts[opcao];
  return hpFinal;
}

const int Engine::setExaust(const int opcao, const int hpStock) {
  if (*this == "Original") return 0;
  const int exaust = Engine::exaustParts[opcao].hpGain;
  const int hpFinal = hpStock + exaust + myTurbo.hpGain
    + myIntake.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  this -> myExaust = Engine::exaustParts[opcao];
  return hpFinal;
}

const int Engine::setECUnit(const int opcao, const int hpStock) {
  if (*this == "Original") return 0;
  const int ECUnit = Engine::ECUnitParts[opcao].hpGain;
  const int hpFinal = hpStock + ECUnit + myTurbo.hpGain
    + myIntake.hpGain + myExaust.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  this -> myECUnit = Engine::ECUnitParts[opcao];
  return hpFinal;
}

const turbo Engine::getTurbo(const int opcao) {
  return Engine::turbosParts[opcao];
}

const intake Engine::getIntake(const int opcao) {
  return Engine::intakeParts[opcao];
}

const exaust Engine::getExaust(const int opcao) {
  return Engine::exaustParts[opcao];
}

const ECUnit Engine::getECUnit(const int opcao) {
  return Engine::ECUnitParts[opcao];
}

const intern Engine::getIntern(const int opcao) {
  return Engine::internParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Engine &engine) {
  output << "Turbo: " << engine.myTurbo.part << "\n";
  output << "Intake: " << engine.myIntake.part << "\n";
  output << "Exaust: " << engine.myExaust.part << "\n";
  output << "ECUnit: " << engine.myECUnit.part << "\n";
  output << "Internals: " << engine.myIntern.part << "\n";
  return output;
}

const Engine &Engine::operator=(const Engine &other) {
  this -> myTurbo = other.myTurbo;
  this -> myIntake = other.myIntake;
  this -> myExaust = other.myExaust;
  this -> myECUnit = other.myECUnit;
  this -> myIntern = other.myIntern;
  return *this;
}

const bool Engine::operator==(const string &part) const {
  return myIntern.part == part;
}

const bool Engine::operator!=(const string &part) const {
  return !(*this == part);
} //Esse

const bool Engine::operator!() const {
  return !(myIntern.hpResis);
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const intern &elem) {
  output << elem.part << " - " << elem.hpResis;
  return output;
}

ostream &operator<<(ostream &output, const turbo &elem) {
  output << elem.part << " - " << elem.hpGain;
  return output;
}

ostream &operator<<(ostream &output, const intake &elem) {
  output << elem.part << " - " << elem.hpGain;
  return output;
}

ostream &operator<<(ostream &output, const exaust &elem) {
  output << elem.part << " - " << elem.hpGain;
  return output;
}

ostream &operator<<(ostream &output, const ECUnit &elem) {
  output << elem.part << " - " << elem.hpGain;
  return output;
}