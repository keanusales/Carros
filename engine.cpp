#include "date.cpp"

// DICIONÁRIOS

const Engine::turbo Engine::turbosParts[] = {
  {"MasterPr 550-AH", 280}, {"Precision 650-LS", 360},
  {"Garrett 750-XT", 450}, {"2x MasterPr 550-AH", 500},
  {"2x Precision 650-LS", 670}, {"2x Garrett 750-XT", 840}
};

const Engine::intake Engine::intakeParts[] = {
  {"2 inch intake, Sport Filter, Original Head", 30},
  {"2.5 inch intake, Sport Filter, Original Head w/ Sport Camshaft", 90},
  {"3 inch intake, Racing Filter, CNC Head w/ Sport Camshaft", 165},
  {"3.5 intake w/ flow work, Racing Filter, CNC Head w/ Racing Camshaft", 260}
};

const Engine::exaust Engine::exaustParts[] = {
  {"3 inch stainless steel exaust w/ Sport Silencers", 70},
  {"3 inch titanium exaust w/ Racing Silencers", 90},
  {"3.5 inch titanium exaust w/ no Silencers", 110}
};

const Engine::ECUnit Engine::ECUnitParts[] = {
  {"Fueltech FT550 w/ Original Harness", 70},
  {"Fueltech FT600 w/ Racing Harness", 100}
};

const Engine::interns Engine::internsParts[] = {
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
  this -> myInterns = {"Original", 0};
}

Engine::Engine(const Engine *other) { *this = other; }

Engine::~Engine() {}

void Engine::setInternals(const int opcao) {
  this -> myInterns = Engine::internsParts[opcao];
}

bool Engine::setTurbo(const int opcao, const int hpAtual) {
  if (*this == "Original") return 0;
  const int hpAdd = Engine::turbosParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myTurbo = Engine::turbosParts[opcao];
  return 1;
}

bool Engine::setIntake(const int opcao, const int hpAtual) {
  if (*this == "Original") return 0;
  const int hpAdd = Engine::intakeParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myIntake = Engine::intakeParts[opcao];
  return 1;
}

bool Engine::setExaust(const int opcao, const int hpAtual) {
  if (!*this) return 0;
  const int hpAdd = Engine::exaustParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myExaust = Engine::exaustParts[opcao];
  return 1;
}

bool Engine::setECUnit(const int opcao, const int hpAtual) {
  if (!*this) return 0;
  const int hpAdd = Engine::ECUnitParts[opcao].hpGain;
  if (hpAdd + hpAtual > myInterns.hpResis) return 0;
  this -> myECUnit = Engine::ECUnitParts[opcao];
  return 1;
}

// SOBRECARGAS

ostream &operator<<(ostream &output, const Engine *engine) {
  output << "Turbo: " << engine->myTurbo.part << "\n";
  output << "Intake: " << engine->myIntake.part << "\n";
  output << "Exaust: " << engine->myExaust.part << "\n";
  output << "ECUnit: " << engine->myECUnit.part << "\n";
  output << "Internals: " << engine->myInterns.part << "\n";
  return output;
}

const Engine &Engine::operator=(const Engine *other) {
  this -> myTurbo = other->myTurbo;
  this -> myIntake = other->myIntake;
  this -> myExaust = other->myExaust;
  this -> myECUnit = other->myECUnit;
  this -> myInterns = other->myInterns;
  return *this;
}

bool Engine::operator==(const string &part) const {
  return myInterns.part == part;
}

bool Engine::operator!=(const string &part) const {
  return !(*this == part);
}

bool Engine::operator!() const {
  return !(myInterns.hpResis);
}