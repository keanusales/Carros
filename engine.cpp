#include "mainf.h"

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
  {"Piston RP-2000+, Rod XXt-2000+, Billet Crankshaft & Block", 2500}
};

// IMPLEMENTAÇÃO

Engine::Engine() {
  this -> myTurbo = {"Original", 0};
  this -> myIntake = {"Original", 0};
  this -> myExaust = {"Original", 0};
  this -> myECUnit = {"Original", 0};
  this -> myIntern = {"Original", 0};
}

Engine::Engine(const Engine &other) {
  this -> myTurbo = other.myTurbo;
  this -> myIntake = other.myIntake;
  this -> myExaust = other.myExaust;
  this -> myECUnit = other.myECUnit;
  this -> myIntern = other.myIntern;
}

Engine::~Engine() {}

const bool Engine::setInternals(const int opcao) {
  const intern intern = Engine::internParts[opcao];
  if (*this == intern) return 0;
  this -> myIntern = intern;
  return 1;
}

const int Engine::setTurbo(const int opcao, const int hpStock) {
  if (!myIntern.hpResis) return 0;
  const turbo turbo = Engine::turbosParts[opcao];
  const int hpFinal = hpStock + turbo.hpGain + myIntake.hpGain
    + myExaust.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  if (*this == turbo) return -1;
  this -> myTurbo = turbo;
  return hpFinal;
}

const int Engine::setIntake(const int opcao, const int hpStock) {
  if (!myIntern.hpResis) return 0;
  const intake intake = Engine::intakeParts[opcao];
  const int hpFinal = hpStock + intake.hpGain + myTurbo.hpGain
    + myExaust.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  if (*this == intake) return -1;
  this -> myIntake = intake;
  return hpFinal;
}

const int Engine::setExaust(const int opcao, const int hpStock) {
  if (!myIntern.hpResis) return 0;
  const exaust exaust = Engine::exaustParts[opcao];
  const int hpFinal = hpStock + exaust.hpGain + myTurbo.hpGain
    + myIntake.hpGain + myECUnit.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  if (*this == exaust) return -1;
  this -> myExaust = exaust;
  return hpFinal;
}

const int Engine::setECUnit(const int opcao, const int hpStock) {
  if (!myIntern.hpResis) return 0;
  const ECUnit ECUnit = Engine::ECUnitParts[opcao];
  const int hpFinal = hpStock + ECUnit.hpGain + myTurbo.hpGain
    + myIntake.hpGain + myExaust.hpGain;
  if (hpFinal > myIntern.hpResis) return 0;
  if (*this == ECUnit) return -1;
  this -> myECUnit = ECUnit;
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
  output << "Turbo: " << engine.myTurbo << "\n";
  output << "Intake: " << engine.myIntake << "\n";
  output << "Exaust: " << engine.myExaust << "\n";
  output << "ECUnit: " << engine.myECUnit << "\n";
  output << "Interns: " << engine.myIntern << "\n";
  return output;
}

const bool Engine::operator==(const turbo &part) const {
  return (myTurbo.hpGain == part.hpGain && myTurbo.part == part.part);
}

const bool Engine::operator==(const intake &part) const {
  return (myIntake.hpGain == part.hpGain && myIntake.part == part.part);
}

const bool Engine::operator==(const exaust &part) const {
  return (myExaust.hpGain == part.hpGain && myExaust.part == part.part);
}

const bool Engine::operator==(const ECUnit &part) const {
  return (myECUnit.hpGain == part.hpGain && myECUnit.part == part.part);
}

const bool Engine::operator==(const intern &part) const {
  return (myIntern.hpResis == part.hpResis && myIntern.part == part.part);
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