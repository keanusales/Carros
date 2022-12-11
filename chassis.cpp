#include "transm.cpp"

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

const double Chassis::MINGFORCE = 1;
const double Chassis::MAXGFORCE = 2;

Chassis::Chassis(const double &gForce) {
  const double temp = gForce / 2;
  this->mySuspens = {"Original", temp};
  this->myChassis = {"Original", temp};
  this->gForce = gForce;
}

Chassis::Chassis(const Chassis &other) {
  this->mySuspens = other.mySuspens;
  this->myChassis = other.myChassis;
  this->gForce = other.gForce;
}

const bool Chassis::setSuspens() {
  const suspens suspens = getSuspens();
  if (*this == suspens) return 0;
  this->gForce = suspens.gForce + myChassis.gForce;
  this->mySuspens = suspens;
  return 1;
}

const bool Chassis::setChassis() {
  const chassis chassis = getChassis();
  if (*this == chassis) return 0;
  this->gForce = chassis.gForce + mySuspens.gForce;
  this->myChassis = chassis;
  return 1;
}

const double Chassis::getGForce() {
  while (1) {
    string input; double gForce;
    cout << "Digite o maximo de Forca G: ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> gForce && MINGFORCE <= gForce
      && gForce <= MAXGFORCE) return gForce;
    system("cls||clear");
    cout << "A Forca G deve ficar entre 1 e 2!\n";
  }
}

const chassis &Chassis::getChassis() {
  unsigned opcao;
  system("cls||clear");
  while (1) {
    string input; unsigned cont = 0;
    for (chassis elem : chassisParts)
      cout << cont++ << " - " << elem << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao && opcao < cont) break;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return Chassis::chassisParts[opcao];
}

const suspens &Chassis::getSuspens() {
  unsigned opcao;
  system("cls||clear");
  while (1) {
    string input; unsigned cont = 0;
    for (suspens elem : suspensParts)
      cout << cont++ << " - " << elem << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao && opcao < cont) break;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return Chassis::suspensParts[opcao];
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Chassis &chassis) {
  output << "Forca G maxima: " << chassis.gForce << "\n";
  output << "Suspension: " << chassis.mySuspens << "\n";
  output << "Chassis: " << chassis.myChassis << "\n";
  return output;
}

const bool Chassis::operator==(const chassis &part) const {
  return (myChassis.gForce == part.gForce && myChassis.part == part.part);
}

const bool Chassis::operator==(const suspens &part) const {
  return (mySuspens.gForce == part.gForce && mySuspens.part == part.part);
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