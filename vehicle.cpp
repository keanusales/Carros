#include "chassis.cpp"

// IMPLEMENTAÇÃO

const unsigned Vehicle::MAXLEN = 40;
unsigned Vehicle::prevRand = 0;

Vehicle::Vehicle(const string &nameVeh) {
  this->nameVeh = nameVeh;
  this->diaCria = getDiaCria();
}

Vehicle::Vehicle(const Vehicle &other) {
  this->nameVeh = other.nameVeh;
  this->diaCria = getDiaCria();
}

Vehicle *Vehicle::create(const unsigned &type) {
  if (type == 1) return new FordF150();
  if (type == 2) return new Mammoth();
  if (type == 3) return new CorvetteZ06();
  if (type == 4) return new PorscheGT2();
  const argCarros args = {
    Vehicle::getNameVeh(),
    Engine::getHpStock(),
    Transm::getTimeSwap(),
    Chassis::getGForce()
  };
  return new Carros(args);
}

const string Vehicle::getNameVeh() {
  while (1) {
    string nameVeh;
    cout << "Digite o nome do veiculo: ";
    getline(cin, nameVeh);
    if (nameVeh.size() <= MAXLEN) return nameVeh;
    system("cls||clear");
    cout << "Nome muito grande! Diminua!\n";
  }
}

const bool Vehicle::verCreate(const unsigned escolha) {
  return (1 <= escolha && escolha <= 5);
}

void Vehicle::setInterns() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setInterns();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setInterns();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setInterns();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setInterns();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setInterns();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setTurbos() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setTurbos();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setTurbos();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setTurbos();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setTurbos();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setTurbos();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setIntake() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setIntake();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setIntake();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setIntake();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setIntake();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setIntake();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setExaust() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setExaust();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setExaust();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setExaust();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setExaust();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setExaust();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setECUnit() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setECUnit();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setECUnit();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setECUnit();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setECUnit();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setECUnit();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setTransm() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setTransm();
    return;
  }
  if (typeid(*this) == typeid(FordF150)) {
    dynamic_cast <FordF150*> (this)->setTransm();
    return;
  }
  if (typeid(*this) == typeid(Mammoth)) {
    dynamic_cast <Mammoth*> (this)->setTransm();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setTransm();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setTransm();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setSuspens() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setSuspens();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setSuspens();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setSuspens();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

void Vehicle::setChassis() {
  if (typeid(*this) == typeid(Carros)) {
    dynamic_cast <Carros*> (this)->setChassis();
    return;
  }
  if (typeid(*this) == typeid(CorvetteZ06)) {
    dynamic_cast <CorvetteZ06*> (this)->setChassis();
    return;
  }
  if (typeid(*this) == typeid(PorscheGT2)) {
    dynamic_cast <PorscheGT2*> (this)->setChassis();
    return;
  }
  system("cls||clear");
  cout << "Nao ha como modificar essa parte!\n";
}

const double Vehicle::random() {
  srand(time(0));
  unsigned atual = prevRand;
  while (atual == prevRand) atual = rand() % 5000;
  Vehicle::prevRand = atual;
  return ((double) atual / 10000) - .25;
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Vehicle &vehicle) {
  output << "Veiculo: " << vehicle.nameVeh << "\n";
  output << "Criacao: " << vehicle.diaCria << "\n\n";
  vehicle.output(output);
  return output;
}

ostream &operator<<(ostream &output, const Vehicle *vehicle) {
  output << vehicle->nameVeh;
  return output;
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const diaCria &elem) {
  output << elem.dia << "/" << elem.mes << "/" << elem.ano;
  return output;
}

const diaCria getDiaCria() {
  const time_t now = time(0);
  const tm ltm = *localtime(&now);
  const unsigned dia = ltm.tm_mday;
  const unsigned mes = 1 + ltm.tm_mon;
  const unsigned ano = 1900 + ltm.tm_year;
  return {dia, mes, ano};
}