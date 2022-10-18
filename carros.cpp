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
  // this -> atributes.upLevel = 0;
  this -> modsDone.turbo = {"Original", 0};
  this -> modsDone.intake = {"Original", 0};
  this -> modsDone.exaust = {"Original", 0};
  this -> modsDone.eletronic = {"Original", 0};
  this -> modsDone.internals = {"Original", 0};
  this -> modsDone.suspension = {"Original", 0};
  this -> modsDone.trasmission = {"Original", 0};
  this -> modsDone.chassis = {"Original", 0};
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
  // cout << "UpLevel: " << atributes.upLevel << "\n\n";
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

void Carros::delModsDone(const int opcao) {
  system("clear||cls");
  switch (opcao) {
    case 0:
      for (Carros::hpGain elem : Carros::turbos)
        if (modsDone.turbo.part == elem.part)
          this -> atributes.hpAtual -= elem.hpGain;
      this -> modsDone.turbo = {"Original", 0};
      break;
    case 1:
      for (Carros::hpGain elem : Carros::intake)
        if (modsDone.intake.part == elem.part)
          this -> atributes.hpAtual -= elem.hpGain;
      this -> modsDone.intake = {"Original", 0};
      break;
    case 2:
      for (Carros::hpGain elem : Carros::exaust)
        if (modsDone.exaust.part == elem.part)
          this -> atributes.hpAtual -= elem.hpGain;
      this -> modsDone.exaust = {"Original", 0};
      break;
    case 3:
      for (Carros::hpGain elem : Carros::eletronics)
        if (modsDone.eletronic.part == elem.part)
          this -> atributes.hpAtual -= elem.hpGain;
      this -> modsDone.eletronic = {"Original", 0};
      break;
    case 4:
      this -> atributes.hpAtual = atributes.hpStock;
      this -> modsDone.internals = {"Original", 0};
      this -> modsDone.turbo = {"Original", 0};
      this -> modsDone.intake = {"Original", 0};
      this -> modsDone.exaust = {"Original", 0};
      this -> modsDone.eletronic = {"Original", 0};
      break;
    case 5:
      this -> modsDone.trasmission = {"Original", 0};
      break;
    case 6:
      this -> modsDone.suspension = {"Original", 0};
      break;
    case 7:
      this -> modsDone.chassis = {"Original", 0};
      break;
    default:
      cout << "Valor Invalido! Tente de novo.\n";
      break;
  }
}

void Carros::setInternals(const int opcao) {
  this -> modsDone.internals = Carros::internals[opcao];
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setTurbo(const int opcao) {
  if (modsDone.internals.part == "Original") {
    system("cls||clear");
    cout << "Internos Originais: Nao e posssivel modificar\n";
    return;
  }
  const int hpAdd = Carros::turbos[opcao].hpGain;
  if (hpAdd + atributes.hpAtual > modsDone.internals.hpResis) {
    system("cls||clear");
    cout << "Internos nao aguentam a nova potencia!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  this -> modsDone.turbo = Carros::turbos[opcao];
  this -> atributes.hpAtual += hpAdd;
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setIntake(const int opcao) {
  if (modsDone.internals.part == "Original") {
    system("cls||clear");
    cout << "Internos Originais: Nao e posssivel modificar\n";
    return;
  }
  const int hpAdd = Carros::intake[opcao].hpGain;
  if (hpAdd + atributes.hpAtual > modsDone.internals.hpResis) {
    system("cls||clear");
    cout << "Internos nao aguentam a nova potencia!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  this -> modsDone.intake = Carros::intake[opcao];
  this -> atributes.hpAtual += hpAdd;
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setExaust(const int opcao) {
  if (modsDone.internals.part == "Original") {
    system("cls||clear");
    cout << "Internos Originais: Nao e posssivel modificar\n";
    return;
  }
  const int hpAdd = Carros::exaust[opcao].hpGain;
  if (hpAdd + atributes.hpAtual > modsDone.internals.hpResis) {
    system("cls||clear");
    cout << "Internos nao aguentam a nova potencia!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  this -> modsDone.exaust = Carros::exaust[opcao];
  this -> atributes.hpAtual += hpAdd;
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setEletronic(const int opcao) {
  if (modsDone.internals.part == "Original") {
    system("cls||clear");
    cout << "Internos Originais: Nao e posssivel modificar\n";
    return;
  }
  const int hpAdd = Carros::eletronics[opcao].hpGain;
  if (hpAdd + atributes.hpAtual > modsDone.internals.hpResis) {
    system("cls||clear");
    cout << "Internos nao aguentam a nova potencia!\n"
      << "Tente fazer um upgrade dos internos!\n";
    return;
  }
  this -> modsDone.eletronic = Carros::eletronics[opcao];
  this -> atributes.hpAtual += hpAdd;
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setTransmission(const int opcao) {
  this -> modsDone.trasmission = Carros::trasmission[opcao];
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setSuspension(const int opcao) {
  this -> modsDone.suspension = Carros::suspension[opcao];
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

void Carros::setChassis(const int opcao) {
  this -> modsDone.chassis = Carros::chassis[opcao];
  system("cls||clear");
  cout << "Atualizacao feita com sucesso!\n";
}

int Carros::getNumCars() { return numCars; }

int Carros::getMaxLen() { return MAXLEN; }

int Carros::getMinHP() { return MINHP; }

int Carros::getMaxHP() { return MAXHP; }

int Carros::getMaxCars() { return MAXCARS; }