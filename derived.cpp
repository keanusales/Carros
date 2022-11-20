#include "trucks.cpp"

// CLASSE SPORTS

const unsigned Sports::HPOWER = 100;

Sports::Sports(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + Sports::HPOWER) {}

Sports::Sports(const Sports &other)
: Carros(static_cast <Carros> (other)) {}

void Sports::calling(const unsigned opcao) {
  typedef void (Sports::*action)();
  const action actions[] = {
    &Sports::printState, &Sports::setInterns, &Sports::setTurbos,
    &Sports::setIntake, &Sports::setExaust, &Sports::setECUnit,
    &Sports::setTransm, &Sports::setSuspens, &Sports::setChassis
  };
  ((*this).*actions[opcao])();
}

void Sports::printState() {
  system("cls||clear"); cout << *this;
}

// SOBRECARGAS DA CLASSE SPORTS

ostream &operator<<(ostream &output, const Sports &sport) {
  output << static_cast <Carros> (sport);
  output << "HP Bonus: " << Sports::HPOWER << "\n\n";
  return output;
}

// CLASSE SUVs

const unsigned SUVs::HPOWER = 50;

SUVs::SUVs(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + SUVs::HPOWER) {}

SUVs::SUVs(const SUVs &other)
: Carros(static_cast <Carros> (other)) {}

void SUVs::calling(const unsigned opcao) {
  typedef void (SUVs::*action)();
  const action actions[] = {
    &SUVs::printState, &SUVs::setInterns, &SUVs::setTurbos,
    &SUVs::setIntake, &SUVs::setExaust, &SUVs::setECUnit,
    &SUVs::setTransm, &SUVs::setSuspens, &SUVs::setChassis
  };
  ((*this).*actions[opcao])();
}

void SUVs::printState() {
  system("cls||clear"); cout << *this;
}

// SOBRECARGAS DA CLASSE SUVs

ostream &operator<<(ostream &output, const SUVs &suv) {
  output << static_cast <Carros> (suv);
  output << "HP Bonus: " << SUVs::HPOWER << "\n\n";
  return output;
}